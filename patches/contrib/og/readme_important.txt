There are 2 patches on og.module that are not in this patches directory. The reason for this is OG's release of 2.7 differs from what we have in code which is marked as 2.7. The reason for this discrepency is unclear. 

Rather than resolving this, the to-do item is to update OG to the latest version (which should be done anyhow) and reapply the patches manually based on what is seen in the git history. The two patches are both referenced with "mukurtu patch". After this is done, a single patch file for both these patches should be created and added to this dir, and this readme removed.


The two Mukurtu patches are now in '132925713-Apply-Mukurtu-og-patches.patch'. 1256956-strict-private.patch and strict-private.patch are nearly the same and neither appear to have been applied for the duration of the GitHub project. A deep dive on OG/Protocols is probably warranted at this point.

Dec 22/2017 - todo -- clean up these patches! - shiraz

