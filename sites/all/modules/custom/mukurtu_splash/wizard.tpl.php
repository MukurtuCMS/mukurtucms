<?php
// output the top wizard of the dashboard

$attribs = array('query'=>array('destination'=>$_GET['q']), 'attributes' => array('class' => array('btn','btn-default')));
$toggle_link = l('Hide Guide', 'wizard/toggle', $attribs);

?>

<?php echo $toggle_link; ?>
<div id="tabs" class="wizard-tabs mukurtu-getting-started">
  <ul>
    <li><a href="#tabs-1">1. Dashboard and Administration</a></li>
    <li><a href="#tabs-2">2. Set up Site</a></li>
    <li><a href="#tabs-3">3. Communities</a></li>
    <li><a href="#tabs-4">4. Cultural Protocols</a></li>
    <li><a href="#tabs-5">5. Categories</a></li>
    <li><a href="#tabs-6">6. Users</a></li>
    <li><a href="#tabs-7">7. Digital Heritage</a></li>
  </ul>

  <!-- Dashboard and Administration -->
  <div id="tabs-1">
    <p>The dashboard provides quick access to all of Mukurtu’s core tools and features. Tools are grouped into boxes by their functions, so that related tools are available together, eg: Set up Site, Site Users, Communities and Protocols, Content and Collections.</p>
    <p>The dashboard is accessible to users with specific site-wide roles: mukurtu administrator, community administrator, and curator. Most users will not have access to the dashboard.</p>
    <p>For more information, read the support articles: Introduction to the <a href="http://support.mukurtu.org/customer/en/portal/articles/2558822-introduction-to-the-mukurtu-administrator-dashboard">Mukurtu Administrator Dashboard</a> and <a href="http://support.mukurtu.org/customer/en/portal/articles/2775579-managing-administrator-roles">Managing Administrator Roles</a>.</p>
  </div>


  <!-- Set up Site -->
  <div id="tabs-2">
    <p>On the dashboard, there is a box labelled 'Set up Site'. It contains quick links to easily change the look and feel of your site. No experience with coding is required to make these changes.</p>
    <p>Look and feel changes include site name, site administrator email, logo, about page, navigation menu items, front page image and welcome text, footer elements, and theme settings.</p>
    <p>All personalizations accessed through this panel are fully supported within Mukurtu and will be preserved when a site is updated to new versions.</p>
    <p>For more information, read the support articles on <a href="http://support.mukurtu.org/customer/en/portal/topics/1077159-site-look-and-feel/articles">Site Look and Feel</a>.</p>
  </div>

  <!-- Communities -->
  <div id="tabs-3">
    <p>Communities are one of the three core elements of every Mukurtu site and are used to group the contributors and users of the site.</p>
    <p>Communities can be large or small, and each Mukurtu site can have as many communities as needed. Mukurtu administrators and community administrators are responsible for creating new communities.</p>
    <p>User access to individual digital heritage items within a community is managed through the cultural protocols that are created within the community.</p>
    <p>Some examples of communities could be specific families or clans, tribal government departments, space for youth-appropriate content, and contributing institutions or departments.</p>
    <p>For more information about creating and managing communities read the support article <a href="http://support.mukurtu.org/customer/en/portal/articles/2432702-how-to-create-communities">How to Create Communities</a>.</p>
  </div>

  <!-- Cultural Protocols -->
  <div id="tabs-4">
    <p>Cultural protocols are one of the three core elements of every Mukurtu site and provide individual users with appropriate access to specific content.</p>
    <p>Each cultural protocol exists within a community, and each community can have multiple cultural protocols. Community managers are responsible for creating new cultural protocols.</p>
    <p>There are two types of cultural protocols: open and strict. Digital heritage items within an open protocol can be viewed by anyone (including anonymous site visitors), while items within a strict protocol can only be viewed by members of that protocol. Multiple protocols can be layered to ensure more granular access. For example, if an item is part of the two strict protocols ‘Women Only’ and ‘Elders Only,’ then only users who are members of both the ‘Women Only’ and ‘Elders Only’ protocols can view that item.</p>
    <p>Some examples of cultural protocols could be gender-based (male only, female only), age-based (elders only, no youth), seasonal access only, clan or tribal affiliation, secret/sacred, community only, or public access/open.</p>
    <p>For more information about creating and managing cultural protocols read the support article <a href="http://support.mukurtu.org/customer/en/portal/articles/2432755-how-to-create-cultural-protocols?b_id=633">How to Create Cultural Protocols</a>.</p>
  </div>

  <!-- Categories -->
  <div id="tabs-5">
    <p>Categories are one of the three core elements of every Mukurtu site and help users browse for and discover digital heritage items.</p>
    <p>Categories are high-level descriptive terms unique to each site that reflect the scope of the items included on the site. One set of categories is used to describe all digital heritage items within the site, and each digital heritage item must belong to at least one category. Mukurtu administrators are responsible for creating new categories.</p>
    <p>Most Mukurtu sites usually have around 10-15 categories, but the categories chosen should reflect the content and user needs. For narrower or more specialized terms, consider using keywords. More information about keywords is available in the support article <a href="http://support.mukurtu.org/customer/en/portal/articles/2430094-using-categories-and-keywords">Using Categories and Keywords</a>.</p>
    <p>For more information about creating and managing categories, read the support article <a href="http://support.mukurtu.org/customer/en/portal/articles/2432734-how-to-create-categories?b_id=633">How to Create Categories</a>.</p>
  </div>

  <!-- Users -->
  <div id="tabs-6">
    <p>There are several user roles available within Mukurtu to help manage user account rights and responsibilities. All users will first need to have a user account created, and then that user account can be assigned roles within cultural protocols and communities as needed. Some users may have additional site-wide administrative roles.</p>
    <p>Mukurtu administrators are responsible for creating/approving new user accounts. Protocol stewards are responsible for managing users within their protocols.</p>
    <p>For more information, read the support articles on <a href="http://support.mukurtu.org/customer/en/portal/topics/1077160-managing-site-users/articles">Managing Site Users</a>.</p>
  </div>

  <!-- Digital Heritage -->
  <div id="tabs-7">
    <p>Digital heritage items are the core content within a Mukurtu site and are usually presented as a media asset (such as an image, video, audio file, or document) with accompanying descriptive metadata used to tell a larger story or narrative. Digital heritage items provide many layers of information through extended features.</p>
    <p>Protocol stewards and contributors are responsible for creating new digital heritage items.</p>
    <p>All digital heritage items must have a title, a community, a cultural protocol, and a category.</p>
    <p>For more information about creating digital heritage items, read the support articles: <a href="http://support.mukurtu.org/customer/portal/articles/2558808-how-to-create-digital-heritage-items">How to Create Digital Heritage Items</a>, and <a href="http://support.mukurtu.org/customer/en/portal/topics/1077148-enriching-digital-heritage/articles">Enriching Digital Heritage</a>.</p>
  </div>
</div>
