#include <stdio.h>
#include "iata_db2.h"

int main(void)
{
  db_t db;
  char key[KEY_LEN+1];
  char *data;

  db_init(&db);
  db_hash_load(&db);

  for (;;) {
    fprintf(stderr, "key = ");
    if (scanf(KEY_FMT, key)==EOF) { break; }
    data = db_hash_search(&db, key);
    if (data==NULL) { printf("NO RECORD\n"); }
    else { printf("%s => %s\n", key, data); }
  }

  db_delete(&db);
  return 0;
}

