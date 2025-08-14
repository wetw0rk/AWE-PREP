/*

Data abstractions are most effective when used with opaque data types that
hide information. Let's say that we want to implement a collection that
supports a limited number of operations, such as adding an element,
removing an element, and searching for an element.

The following example implements collection_type as an opaque type, hiding
the implementation details of the data type from the library's user.

To accomplish this, we create two header files: an external collection.h
header file included by the user of the data type, and an internal file
included only in files that implement the functionaloty of the data type.

*/

/* In the external collection.h header file, the collection_type data
   type is defined as an instance of struct collection_type, which is
   an incomplete type: */
typedef struct collection_type collection_type;
// Function declarations
extern errno_t create_collection(collection_type ** result);
extern void destroy_collection(collection_type *col);
extern errno_t add_to_collection(collection_type *col, const void *data, size_t byteCount);
extern errno_t remove_from_collection(collection_type *col, const void *data, size_t byteCount);
extern errno_t find_in_collection(const collection_type *col, const void *data, size_t byteCount);
// ---snip---

/* In the internal header file, struct collection_type is fully defined
   but not visible to a user of the data abstraction */
struct node_type {
  void *data;
  size_t size;
  struct node_type *next;
};

struct collection_type {
  size_t num_elements;
  struct node_type *head;
};

/* Modules that implement the abstract data type include both the
   external and internal definitions, whereas users of the data
   abstraction include only the external collection.h file. This
   allows the implementation of the collection_type data type to
   remain private. */
