#include "toml.h"

int main() {
  TomlTable *table = toml_load_filename("example.toml");
  TomlTableIter iter = toml_table_iter_new(table);
  TomlKeyValue *kv = NULL;
  int i = 0;

idk:
  kv = toml_table_iter_get(&iter);

  if (kv) {
    printf("[%s] ", kv->key->str);

    switch (kv->value->type) {
    case TOML_TABLE:
      printf("{table}\n");
      break;
    case TOML_ARRAY:
      printf("{array}\n");
      break;
    case TOML_STRING:
      printf("%s\n", kv->value->value.string->str);
      break;
    case TOML_INTEGER:
      printf("%ld\n", kv->value->value.integer);
      break;
    case TOML_FLOAT:
      printf("%0.2f\n", kv->value->value.float_);
      break;
    case TOML_DATETIME:
      printf("{datetime}\n");
      break;
    case TOML_BOOLEAN:
      printf("%s\n", kv->value ? "true" : "false");
      break;
    };
  }

  if (toml_table_iter_has_next(&iter)) {
    toml_table_iter_next(&iter);
    goto idk;
  }
}