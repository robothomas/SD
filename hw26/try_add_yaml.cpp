#include"/usr/local/cs/cs251/react.h"

int main() {
  _add_yaml("button.yaml", {{"id", 1}, {"r", 10}, {"g", 10}, {"b", 10}, {"r2", 200}, {"g2", 200}, {"b2", 200}});
  _write_global_yaml_to_file("react.yaml");
}
