// table.h: an abstract API for tables with string keys.
//
// Written by Tony Finch <dot@dotat.at>
// You may do anything with this. It has no warranty.
// <http://creativecommons.org/publicdomain/zero/1.0/>

#ifndef Tbl_h
#define Tbl_h

// A table is represented by a pointer to this incomplete struct type.
// You initialize an empty table by setting the pointer to NULL.
//
typedef struct Tbl Tbl;

// Get the value associated with a key.
// Returns NULL if the key is not in the Table.
//
void *Tgetl(Tbl *tbl, const char *key, size_t klen);
void *Tget(Tbl *tbl, const char *key);

// Associate a key with a value in a table. Returns a new pointer to
// the modified table. If there is an error it sets errno and returns
// NULL. To delete a key, set its value to NULL. When the last key is
// deleted, Tset() returns NULL without setting errno. The key and
// value are borrowed not copied.
//
// Errors:
// EINVAL - value pointer is not word-aligned
// ENOMEM - allocation failed
//
Tbl *Tsetl(Tbl *tbl, const char *key, size_t klen, void *value);
Tbl *Tset(Tbl *tbl, const char *key, void *value);
Tbl *Tdell(Tbl *tbl, const char *key, size_t klen);
Tbl *Tdel(Tbl *tbl, const char *key);

// Find the next item in the table. The p... arguments are in/out
// parameters. To find the first key, pass *pkey = NULL.
// Returns false or NULL when there are no more keys.
//
bool Tnextl(Tbl *tbl, const char **pkey, size_t *pklen, void **pvalue);
bool Tnext(Tbl *tbl, const char **pkey, void **pvalue);
const char *Tnxt(Tbl *tbl, const char *key);

#endif // Tbl_h
