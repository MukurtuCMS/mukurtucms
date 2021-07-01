<?php

/**
 * @file
 * =============================================================================.
 *
 * ctools_math_expr - PHP Class to safely evaluate math expressions
 * Copyright (C) 2005 Miles Kaufmann <http://www.twmagic.com/>
 *
 * =============================================================================
 *
 * NAME
 *     ctools_math_expr - safely evaluate math expressions
 *
 * SYNOPSIS
 *     $m = new ctools_math_expr();
 *     // basic evaluation:
 *     $result = $m->evaluate('2+2');
 *     // supports: order of operation; parentheses; negation; built-in
 *     // functions.
 *     $result = $m->evaluate('-8(5/2)^2*(1-sqrt(4))-8');
 *     // create your own variables
 *     $m->evaluate('a = e^(ln(pi))');
 *     // or functions
 *     $m->evaluate('f(x,y) = x^2 + y^2 - 2x*y + 1');
 *     // and then use them
 *     $result = $m->evaluate('3*f(42,a)');
 *
 * DESCRIPTION
 *     Use the ctools_math_expr class when you want to evaluate mathematical
 *     expressions from untrusted sources.  You can define your own variables
 *     and functions, which are stored in the object.  Try it, it's fun!
 *
 * AUTHOR INFORMATION
 *     Copyright 2005, Miles Kaufmann.
 *     Enhancements, 2005 onwards, Drupal Community.
 *
 * LICENSE
 *     Redistribution and use in source and binary forms, with or without
 *     modification, are permitted provided that the following conditions are
 *     met:
 *
 *     1   Redistributions of source code must retain the above copyright
 *         notice, this list of conditions and the following disclaimer.
 *     2.  Redistributions in binary form must reproduce the above copyright
 *         notice, this list of conditions and the following disclaimer in the
 *         documentation and/or other materials provided with the distribution.
 *     3.  The name of the author may not be used to endorse or promote
 *         products derived from this software without specific prior written
 *         permission.
 *
 *     THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 *     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *     DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 *     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 *     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *     ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *     POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * ctools_math_expr Class.
 */
class ctools_math_expr {

  /**
   * If TRUE do not call trigger_error on error other wise do.
   *
   * @var bool
   */
  public $suppress_errors = FALSE;

  /**
   * The last error message reported.
   *
   * @var string
   */
  public $last_error = NULL;

  /**
   * List of all errors reported.
   *
   * @var array
   */
  public $errors = array();

  /**
   * Variable and constant values.
   *
   * @var array
   */
  protected $vars;

  /**
   * User defined functions.
   *
   * @var array
   */
  protected $userfuncs;

  /**
   * The names of constants, used to make constants read-only.
   *
   * @var array
   */
  protected $constvars;

  /**
   * Built in simple (one arg) functions.
   * Merged into $this->funcs in constructor.
   *
   * @var array
   */
  protected $simplefuncs;

  /**
   * Definitions of all built-in functions.
   *
   * @var array
   */
  protected $funcs;

  /**
   * Operators and their precedence.
   *
   * @var array
   */
  protected $ops;

  /**
   * The set of operators using two arguments.
   *
   * @var array
   */
  protected $binaryops;

  /**
   * Public constructor.
   */
  public function __construct() {
    $this->userfuncs = array();
    $this->simplefuncs = array(
      'sin',
      'sinh',
      'asin',
      'asinh',
      'cos',
      'cosh',
      'acos',
      'acosh',
      'tan',
      'tanh',
      'atan',
      'atanh',
      'exp',
      'sqrt',
      'abs',
      'log',
      'ceil',
      'floor',
      'round',
    );

    $this->ops = array(
      '+' => array('precedence' => 0),
      '-' => array('precedence' => 0),
      '*' => array('precedence' => 1),
      '/' => array('precedence' => 1),
      '^' => array('precedence' => 2, 'right' => TRUE),
      '_' => array('precedence' => 1),
      '==' => array('precedence' => -1),
      '!=' => array('precedence' => -1),
      '>=' => array('precedence' => -1),
      '<=' => array('precedence' => -1),
      '>' => array('precedence' => -1),
      '<' => array('precedence' => -1),
    );

    $this->binaryops = array(
      '+', '-', '*', '/', '^', '==', '!=', '<', '<=', '>=', '>',
    );

    $this->funcs = array(
      'ln' => array(
        'function' => 'log',
        'arguments' => 1,
      ),
      'arcsin' => array(
        'function' => 'asin',
        'arguments' => 1,
      ),
      'arcsinh' => array(
        'function' => 'asinh',
        'arguments' => 1,
      ),
      'arccos' => array(
        'function' => 'acos',
        'arguments' => 1,
      ),
      'arccosh' => array(
        'function' => 'acosh',
        'arguments' => 1,
      ),
      'arctan' => array(
        'function' => 'atan',
        'arguments' => 1,
      ),
      'arctanh' => array(
        'function' => 'atanh',
        'arguments' => 1,
      ),
      'min' => array(
        'function' => 'min',
        'arguments' => 2,
        'max arguments' => 99,
      ),
      'max' => array(
        'function' => 'max',
        'arguments' => 2,
        'max arguments' => 99,
      ),
      'pow' => array(
        'function' => 'pow',
        'arguments' => 2,
      ),
      'if' => array(
        'function' => 'ctools_math_expr_if',
        'arguments' => 2,
        'max arguments' => 3,
      ),
      'number' => array(
        'function' => 'ctools_math_expr_number',
        'arguments' => 1,
      ),
      'time' => array(
        'function' => 'time',
        'arguments' => 0,
      ),
    );

    // Allow modules to add custom functions.
    $context = array('final' => &$this->funcs);
    drupal_alter('ctools_math_expression_functions', $this->simplefuncs, $context);

    // Set up the initial constants and mark them read-only.
    $this->vars = array('e' => exp(1), 'pi' => pi());
    drupal_alter('ctools_math_expression_constants', $this->vars);
    $this->constvars = array_keys($this->vars);

    // Translate the older, simpler style into the newer, richer style.
    foreach ($this->simplefuncs as $function) {
      $this->funcs[$function] = array(
        'function' => $function,
        'arguments' => 1,
      );
    }
  }

  /**
   * Change the suppress errors flag.
   *
   * When errors are not suppressed, trigger_error is used to cause a PHP error
   * when an evaluation error occurs, as a result of calling trigger(). With
   * errors suppressed this doesn't happen.
   *
   * @param bool $enable
   *   If FALSE, enable triggering of php errors when expression errors occurs.
   *   otherwise, suppress triggering the errors.
   *
   * @return bool
   *   The new (current) state of the flag.
   *
   * @see ctools_math_expr::trigger()
   */
  public function set_suppress_errors($enable) {
    return $this->suppress_errors = (bool) $enable;
  }

  /**
   * Backwards compatible wrapper for evaluate().
   *
   * @see ctools_math_expr::evaluate()
   */
  public function e($expr) {
    return $this->evaluate($expr);
  }

  /**
   * Evaluate the expression.
   *
   * @param string $expr
   *   The expression to evaluate.
   *
   * @return string|bool
   *   The result of the expression, or FALSE if an error occurred, or TRUE if
   *   an user-defined function was created.
   */
  public function evaluate($expr) {
    $this->last_error = NULL;
    $expr = trim($expr);

    // Strip possible semicolons at the end.
    if (substr($expr, -1, 1) == ';') {
      $expr = substr($expr, 0, -1);
    }

    // Is it a variable assignment?
    if (preg_match('/^\s*([a-z]\w*)\s*=\s*(.+)$/', $expr, $matches)) {

      // Make sure we're not assigning to a constant.
      if (in_array($matches[1], $this->constvars)) {
        return $this->trigger("cannot assign to constant '$matches[1]'");
      }

      // Get the result and make sure it's good:
      if (($tmp = $this->pfx($this->nfx($matches[2]))) === FALSE) {
        return FALSE;
      }
      // If so, stick it in the variable array...
      $this->vars[$matches[1]] = $tmp;
      // ...and return the resulting value:
      return $this->vars[$matches[1]];

    }
    // Is it a function assignment?
    elseif (preg_match('/^\s*([a-z]\w*)\s*\(\s*([a-z]\w*(?:\s*,\s*[a-z]\w*)*)\s*\)\s*=\s*(.+)$/', $expr, $matches)) {
      // Get the function name.
      $fnn = $matches[1];
      // Make sure it isn't built in:
      if (isset($this->funcs[$matches[1]])) {
        return $this->trigger("cannot redefine built-in function '$matches[1]()'");
      }

      // Get the arguments.
      $args = explode(",", preg_replace("/\s+/", "", $matches[2]));
      // See if it can be converted to postfix.
      $stack = $this->nfx($matches[3]);
      if ($stack === FALSE) {
        return FALSE;
      }

      // Freeze the state of the non-argument variables.
      for ($i = 0; $i < count($stack); $i++) {
        $token = $stack[$i];
        if (preg_match('/^[a-z]\w*$/', $token) and !in_array($token, $args)) {
          if (array_key_exists($token, $this->vars)) {
            $stack[$i] = $this->vars[$token];
          }
          else {
            return $this->trigger("undefined variable '$token' in function definition");
          }
        }
      }
      $this->userfuncs[$fnn] = array('args' => $args, 'func' => $stack);

      return TRUE;
    }
    else {
      // Straight up evaluation.
      return trim($this->pfx($this->nfx($expr)), '"');
    }
  }

  /**
   * Fetch an array of variables used in the expression.
   *
   * @return array
   *   Array of name : value pairs, one for each variable defined.
   */
  public function vars() {
    $output = $this->vars;

    // @todo: Is this supposed to remove all constants? we should remove all
    // those in $this->constvars!
    unset($output['pi']);
    unset($output['e']);

    return $output;
  }

  /**
   * Fetch all user defined functions in the expression.
   *
   * @return array
   *   Array of name : string pairs, one for each function defined. The string
   *   will be of the form fname(arg1,arg2). The function body is not returned.
   */
  public function funcs() {
    $output = array();
    foreach ($this->userfuncs as $fnn => $dat) {
      $output[] = $fnn . '(' . implode(',', $dat['args']) . ')';
    }

    return $output;
  }

  /**
   * Convert infix to postfix notation.
   *
   * @param string $expr
   *   The expression to convert.
   *
   * @return array|bool
   *   The expression as an ordered list of postfix action tokens.
   */
  private function nfx($expr) {

    $index = 0;
    $stack = new ctools_math_expr_stack();
    // Postfix form of expression, to be passed to pfx().
    $output = array();

    // @todo: Because the expr can contain string operands, using strtolower here is a bug.
    $expr = trim(strtolower($expr));

    // We use this in syntax-checking the expression and determining when
    // '-' is a negation.
    $expecting_op = FALSE;

    while (TRUE) {
      $op = substr($expr, $index, 1);
      // Get the first character at the current index, and if the second
      // character is an =, add it to our op as well (accounts for <=).
      if (substr($expr, $index + 1, 1) === '=') {
        $op = substr($expr, $index, 2);
        $index++;
      }

      // Find out if we're currently at the beginning of a number/variable/
      // function/parenthesis/operand.
      $ex = preg_match('/^([a-z]\w*\(?|\d+(?:\.\d*)?|\.\d+|\()/', substr($expr, $index), $match);

      // Is it a negation instead of a minus?
      if ($op === '-' and !$expecting_op) {
        // Put a negation on the stack.
        $stack->push('_');
        $index++;
      }
      // We have to explicitly deny this, because it's legal on the stack but
      // not in the input expression.
      elseif ($op == '_') {
        return $this->trigger("illegal character '_'");

      }
      // Are we putting an operator on the stack?
      elseif ((isset($this->ops[$op]) || $ex) && $expecting_op) {
        // Are we expecting an operator but have a num, var, func, or
        // open-paren?
        if ($ex) {
          $op = '*';
          // It's an implicit multiplication.
          $index--;
        }
        // Heart of the algorithm:
        while ($stack->count() > 0 &&
          ($o2 = $stack->last()) &&
          isset($this->ops[$o2]) &&
          (!empty($this->ops[$op]['right']) ?
            $this->ops[$op]['precedence'] < $this->ops[$o2]['precedence'] :
            $this->ops[$op]['precedence'] <= $this->ops[$o2]['precedence'])) {

          // Pop stuff off the stack into the output.
          $output[] = $stack->pop();
        }
        // Many thanks: http://en.wikipedia.org/wiki/Reverse_Polish_notation#The_algorithm_in_detail
        // finally put OUR operator onto the stack.
        $stack->push($op);
        $index++;
        $expecting_op = FALSE;

      }
      // Ready to close a parenthesis?
      elseif ($op === ')') {

        // Pop off the stack back to the last '('.
        while (($o2 = $stack->pop()) !== '(') {
          if (is_null($o2)) {
            return $this->trigger("unexpected ')'");
          }
          else {
            $output[] = $o2;
          }
        }

        // Did we just close a function?
        if (preg_match("/^([a-z]\w*)\($/", $stack->last(2), $matches)) {

          // Get the function name.
          $fnn = $matches[1];
          // See how many arguments there were (cleverly stored on the stack,
          // thank you).
          $arg_count = $stack->pop();
          // Pop the function and push onto the output.
          $output[] = $stack->pop();

          // Check the argument count:
          if (isset($this->funcs[$fnn])) {
            $fdef = $this->funcs[$fnn];
            $max_arguments = isset($fdef['max arguments']) ? $fdef['max arguments'] : $fdef['arguments'];
            if ($arg_count > $max_arguments) {
              return $this->trigger("too many arguments ($arg_count given, $max_arguments expected)");
            }
          }
          elseif (array_key_exists($fnn, $this->userfuncs)) {
            $fdef = $this->userfuncs[$fnn];
            if ($arg_count !== count($fdef['args'])) {
              return $this->trigger("wrong number of arguments ($arg_count given, " . count($fdef['args']) . ' expected)');
            }
          }
          else {
            // Did we somehow push a non-function on the stack? this should
            // never happen.
            return $this->trigger('internal error');
          }
        }
        $index++;

      }
      // Did we just finish a function argument?
      elseif ($op === ',' && $expecting_op) {
        $index++;
        $expecting_op = FALSE;
      }
      elseif ($op === '(' && !$expecting_op) {
        $stack->push('(');
        $index++;

      }
      elseif ($ex && !$expecting_op) {
        // Make sure there was a function.
        if (preg_match("/^([a-z]\w*)\($/", $stack->last(3), $matches)) {
          // Pop the argument expression stuff and push onto the output:
          while (($o2 = $stack->pop()) !== '(') {
            // Oops, never had a '('.
            if (is_null($o2)) {
              return $this->trigger("unexpected argument in $expr $o2");
            }
            else {
              $output[] = $o2;
            }
          }

          // Increment the argument count.
          $stack->push($stack->pop() + 1);
          // Put the ( back on, we'll need to pop back to it again.
          $stack->push('(');
        }

        // Do we now have a function/variable/number?
        $expecting_op = TRUE;
        $val = $match[1];
        if (preg_match("/^([a-z]\w*)\($/", $val, $matches)) {
          // May be func, or variable w/ implicit multiplication against
          // parentheses...
          if (isset($this->funcs[$matches[1]]) or array_key_exists($matches[1], $this->userfuncs)) {
            $stack->push($val);
            $stack->push(0);
            $stack->push('(');
            $expecting_op = FALSE;
          }
          // it's a var w/ implicit multiplication.
          else {
            $val = $matches[1];
            $output[] = $val;
          }
        }
        // it's a plain old var or num.
        else {
          $output[] = $val;
        }
        $index += strlen($val);

      }
      elseif ($op === ')') {
        // Miscellaneous error checking.
        return $this->trigger("unexpected ')'");
      }
      elseif (isset($this->ops[$op]) and !$expecting_op) {
        return $this->trigger("unexpected operator '$op'");
      }
      elseif ($op === '"') {
        // Fetch a quoted string.
        $string = substr($expr, $index);
        if (preg_match('/"[^"\\\\]*(?:\\\\.[^"\\\\]*)*"/s', $string, $matches)) {
          $string = $matches[0];
          // Trim the quotes off:
          $output[] = $string;
          $index += strlen($string);
          $expecting_op = TRUE;
        }
        else {
          return $this->trigger('open quote without close quote.');
        }
      }
      else {
        // I don't even want to know what you did to get here.
        return $this->trigger("an unexpected error occurred at $op");
      }
      if ($index === strlen($expr)) {
        if (isset($this->ops[$op])) {
          // Did we end with an operator? bad.
          return $this->trigger("operator '$op' lacks operand");
        }
        else {
          break;
        }
      }

      // Step the index past whitespace (pretty much turns whitespace into
      // implicit multiplication if no operator is there).
      while (substr($expr, $index, 1) === ' ') {
        $index++;
      }
    }

    // Pop everything off the stack and push onto output:
    while (!is_null($op = $stack->pop())) {

      // If there are (s on the stack, ()s were unbalanced.
      if ($op === '(') {
        return $this->trigger("expecting ')'");
      }
      $output[] = $op;
    }

    return $output;
  }

  /**
   * Evaluate a prefix-operator stack expression.
   *
   * @param array $tokens
   *   The array of token values to evaluate. A token is a string value
   *   representing either an operation to perform, a variable, or a value.
   *   Literal values are checked using is_numeric(), or a value that starts
   *   with a double-quote; functions and variables by existence in the
   *   appropriate tables.
   *   If FALSE is passed in the function terminates immediately, returning
   *   FALSE.
   * @param array $vars
   *   Additional variable values to use when evaluating the expression. These
   *   variables do not override internal variables with the same name.
   *
   * @return bool|mixed
   *   The expression's value, otherwise FALSE is returned if there is an error
   *   detected unless php error handling intervenes: see suppress_error.
   */
  public function pfx(array $tokens, array $vars = array()) {

    if ($tokens == FALSE) {
      return FALSE;
    }

    $stack = new ctools_math_expr_stack();

    foreach ($tokens as $token) {
      // If the token is a binary operator, pop two values off the stack, do
      // the operation, and push the result back on again.
      if (in_array($token, $this->binaryops)) {
        if (is_null($op2 = $stack->pop())) {
          return $this->trigger('internal error');
        }
        if (is_null($op1 = $stack->pop())) {
          return $this->trigger('internal error');
        }
        switch ($token) {
          case '+':
            $stack->push($op1 + $op2);
            break;

          case '-':
            $stack->push($op1 - $op2);
            break;

          case '*':
            $stack->push($op1 * $op2);
            break;

          case '/':
            if ($op2 == 0) {
              return $this->trigger('division by zero');
            }
            $stack->push($op1 / $op2);
            break;

          case '^':
            $stack->push(pow($op1, $op2));
            break;

          case '==':
            $stack->push((int) ($op1 == $op2));
            break;

          case '!=':
            $stack->push((int) ($op1 != $op2));
            break;

          case '<=':
            $stack->push((int) ($op1 <= $op2));
            break;

          case '<':
            $stack->push((int) ($op1 < $op2));
            break;

          case '>=':
            $stack->push((int) ($op1 >= $op2));
            break;

          case '>':
            $stack->push((int) ($op1 > $op2));
            break;
        }
      }
      // If the token is a unary operator, pop one value off the stack, do the
      // operation, and push it back on again.
      elseif ($token === "_") {
        $stack->push(-1 * $stack->pop());
      }
      // If the token is a function, pop arguments off the stack, hand them to
      // the function, and push the result back on again.
      elseif (preg_match("/^([a-z]\w*)\($/", $token, $matches)) {
        $fnn = $matches[1];

        // Check for a built-in function.
        if (isset($this->funcs[$fnn])) {
          $args = array();
          // Collect all required args from the stack.
          for ($i = 0; $i < $this->funcs[$fnn]['arguments']; $i++) {
            if (is_null($op1 = $stack->pop())) {
              return $this->trigger("function $fnn missing argument $i");
            }
            $args[] = $op1;
          }
          // If func allows additional args, collect them too, stopping on a
          // NULL arg.
          if (!empty($this->funcs[$fnn]['max arguments'])) {
            for (; $i < $this->funcs[$fnn]['max arguments']; $i++) {
              $arg = $stack->pop();
              if (!isset($arg)) {
                break;
              }
              $args[] = $arg;
            }
          }
          $stack->push(
            call_user_func_array($this->funcs[$fnn]['function'], array_reverse($args))
          );
        }

        // Check for a user function.
        elseif (isset($fnn, $this->userfuncs)) {
          $args = array();
          for ($i = count($this->userfuncs[$fnn]['args']) - 1; $i >= 0; $i--) {
            $value = $stack->pop();
            $args[$this->userfuncs[$fnn]['args'][$i]] = $value;
            if (is_null($value)) {
              return $this->trigger('internal error');
            }
          }
          // yay... recursion!!!!
          $stack->push($this->pfx($this->userfuncs[$fnn]['func'], $args));
        }
      }
      // If the token is a number or variable, push it on the stack.
      else {
        if (is_numeric($token) || $token[0] == '"') {
          $stack->push($token);
        }
        elseif (array_key_exists($token, $this->vars)) {
          $stack->push($this->vars[$token]);
        }
        elseif (array_key_exists($token, $vars)) {
          $stack->push($vars[$token]);
        }
        else {
          return $this->trigger("undefined variable '$token'");
        }
      }
    }
    // When we're out of tokens, the stack should have a single element, the
    // final result:
    if ($stack->count() !== 1) {
      return $this->trigger('internal error');
    }

    return $stack->pop();
  }

  /**
   * Trigger an error, but nicely, if need be.
   *
   * @param string $msg
   *   Message to add to trigger error.
   *
   * @return bool
   *   Can trigger error, then returns FALSE.
   */
  protected function trigger($msg) {
    $this->errors[] = $msg;
    $this->last_error = $msg;
    if (!$this->suppress_errors) {
      trigger_error($msg, E_USER_WARNING);
    }

    return FALSE;
  }

}

/**
 * Class implementing a simple stack structure, used by ctools_math_expr.
 */
class ctools_math_expr_stack {

  /**
   * The stack.
   *
   * @var array
   */
  private $stack;
  /**
   * The stack pointer, points at the first empty space.
   *
   * @var int
   */
  private $count;

  /**
   * Ctools_math_expr_stack constructor.
   */
  public function __construct() {
    $this->stack = array();
    $this->count = 0;
  }

  /**
   * Push the value onto the stack.
   *
   * @param mixed $val
   */
  public function push($val) {
    $this->stack[$this->count] = $val;
    $this->count++;
  }

  /**
   * Remove the most recently pushed value and return it.
   *
   * @return mixed|null
   *   The most recently pushed value, or NULL if the stack was empty.
   */
  public function pop() {
    if ($this->count > 0) {
      $this->count--;

      return $this->stack[$this->count];
    }
    return NULL;
  }

  /**
   * "Peek" the stack, or Return a value from the stack without removing it.
   *
   * @param int $n
   *   Integer indicating which value to return. 1 is the topmost (i.e. the
   *   value that pop() would return), 2 indicates the next, 3 the third, etc.
   *
   * @return mixed|null
   *   A value pushed onto the stack at the nth position, or NULL if the stack
   *   was empty.
   */
  public function last($n = 1) {
    return !empty($this->stack[$this->count - $n]) ? $this->stack[$this->count - $n] : NULL;
  }

  /**
   * Return the number of items on the stack.
   *
   * @return int
   *   The number of items.
   */
  public function count() {
    return $this->count;
  }

}

/**
 * Helper function for evaluating 'if' condition.
 *
 * @param int $expr
 *   The expression to test: if <> 0 then the $if expression is returned.
 * @param mixed $if
 *   The expression returned if the condition is true.
 * @param mixed $else
 *   Optional. The expression returned if the expression is false.
 *
 * @return mixed|null
 *   The result. NULL is returned when an If condition is False and no Else
 *   expression is provided.
 */
function ctools_math_expr_if($expr, $if, $else = NULL) {
  return $expr ? $if : $else;
}

/**
 * Remove any non-digits so that numbers like $4,511.23 still work.
 *
 * It might be good for those using the 12,345.67 format, but is awful for
 * those using other conventions.
 * Use of the php 'intl' module might work here, if the correct locale can be
 * derived, but that seems unlikely to be true in all cases.
 *
 * @todo: locale could break this since in some locales that's $4.512,33 so
 * there needs to be a way to detect that and make it work properly.
 *
 * @param mixed $arg
 *   A number string with possible leading chars.
 *
 * @return mixed
 *   Returns a number string.
 */
function ctools_math_expr_number($arg) {
  // @todo: A really bad idea: It might be good for those using the 12,345.67
  // format, but is awful for those using other conventions.
  // $arg = preg_replace("/[^0-9\.]/", '', $arg);.
  return $arg;
}
