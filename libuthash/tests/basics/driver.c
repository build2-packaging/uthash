#include <stdlib.h>
#include <string.h>

#include <uthash.h>
#include <utlist.h>
#include <utarray.h>
#include <utstring.h>
#include <utstack.h>
#include <utringbuffer.h>

#undef NDEBUG
#include <assert.h>

struct entry
{
  int key;
  int value;
  UT_hash_handle hh;
};

struct node
{
  int value;
  struct node *prev, *next;
};

int main (void)
{
  /* Hash table (uthash.h).
   */
  {
    struct entry *table = NULL, *e, *t;
    int i;

    for (i = 0; i < 100; i++)
    {
      e = (struct entry *) malloc (sizeof (struct entry));
      assert (e != NULL);
      e->key = i;
      e->value = i * i;
      HASH_ADD_INT (table, key, e);
    }

    assert (HASH_COUNT (table) == 100);

    i = 42;
    HASH_FIND_INT (table, &i, e);
    assert (e != NULL && e->value == 42 * 42);

    i = 100;
    HASH_FIND_INT (table, &i, e);
    assert (e == NULL);

    HASH_ITER (hh, table, e, t)
    {
      HASH_DEL (table, e);
      free (e);
    }

    assert (table == NULL);
  }

  /* Doubly-linked list (utlist.h).
   */
  {
    struct node n[3], *head = NULL, *e;
    int i, c;

    for (i = 0; i < 3; i++)
    {
      n[i].value = i;
      DL_APPEND (head, &n[i]);
    }

    DL_COUNT (head, e, c);
    assert (c == 3 && head->value == 0 && head->prev->value == 2);

    DL_DELETE (head, &n[0]);
    assert (head->value == 1);
  }

  /* Dynamic array (utarray.h).
   */
  {
    UT_array *a;
    int i, *p;

    utarray_new (a, &ut_int_icd);

    for (i = 0; i < 10; i++)
      utarray_push_back (a, &i);

    assert (utarray_len (a) == 10);

    p = (int *) utarray_eltptr (a, 5);
    assert (p != NULL && *p == 5);

    utarray_free (a);
  }

  /* Dynamic string (utstring.h).
   */
  {
    UT_string *s;

    utstring_new (s);
    utstring_printf (s, "Hello, %s!", "World");
    assert (utstring_len (s) == 13 &&
            strcmp (utstring_body (s), "Hello, World!") == 0);
    utstring_free (s);
  }

  /* Stack (utstack.h).
   */
  {
    struct node n[2], *stack = NULL, *e;
    int c;

    n[0].value = 1;
    n[1].value = 2;
    STACK_PUSH (stack, &n[0]);
    STACK_PUSH (stack, &n[1]);

    STACK_COUNT (stack, e, c);
    assert (c == 2 && STACK_TOP (stack)->value == 2);

    STACK_POP (stack, e);
    assert (e->value == 2 && STACK_TOP (stack)->value == 1);
  }

  /* Ring buffer (utringbuffer.h).
   */
  {
    UT_ringbuffer *r;
    int i;

    utringbuffer_new (r, 3, &ut_int_icd);

    for (i = 0; i < 5; i++)
      utringbuffer_push_back (r, &i);

    assert (utringbuffer_len (r) == 3);
    assert (*(int *) utringbuffer_front (r) == 2 &&
            *(int *) utringbuffer_back (r) == 4);

    utringbuffer_free (r);
  }

  return 0;
}
