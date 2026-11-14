# uthash - <SUMMARY>

This is a `build2` package repository for [`uthash`](https://<UPSTREAM-URL>),
a <SUMMARY-OF-FUNCTIONALITY>.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`uthash` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](<PACKAGE>/PACKAGE-README.md) file.

The development setup for `uthash` uses the standard `bdep`-based workflow.
For example:

```
git clone .../uthash.git
cd uthash

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
