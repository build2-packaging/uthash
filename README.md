# uthash - Macro-based hash table and data structure C library

This is a `build2` package repository for [`uthash`](https://github.com/troydhanson/uthash),
a hash table for C structures together with linked list, dynamic array,
dynamic string, stack, and ring buffer macros.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`uthash` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](libuthash/PACKAGE-README.md) file.

The development setup for `uthash` uses the standard `bdep`-based workflow.
For example:

```
git clone --recurse-submodules https://github.com/build2-packaging/uthash.git
cd uthash

bdep init -C @gcc cc config.c=gcc
bdep update
bdep test
```
