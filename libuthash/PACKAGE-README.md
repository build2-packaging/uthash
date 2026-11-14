# libuthash - Macro-based hash table and data structure C library

This is a `build2` package for the [`uthash`](https://github.com/troydhanson/uthash)
C library. It provides a hash table for C structures: any C structure can be
stored in a hash table by adding a `UT_hash_handle` to the structure and
choosing one or more fields in the structure to act as the key. It also
provides linked list, dynamic array, dynamic string, stack, and ring buffer
macros.


## Usage

To start using `libuthash` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libuthash ^2.4.0
```

Then import the library in your `buildfile`:

```
import libs = libuthash%lib{uthash}
```


## Importable targets

This package provides the following importable targets:

```
lib{uthash}
```

Header-only library that provides the `uthash.h`, `utlist.h`, `utarray.h`,
`utstring.h`, `utstack.h`, and `utringbuffer.h` headers. They are included
without a directory prefix, for example, `#include <uthash.h>`.


## Configuration variables

This package provides no configuration variables.
