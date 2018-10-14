#include <string>
#include <vector>

class Command {
  std::string filename;
  std::vector<std::string> args;
public:
  Command(std::string filename, std::vector<std::string> args);
  invoke();
}
//Alex
class Shell {
//TODO:  Determine command structure
//TODO:  Main loop structure (read print evaluate loop)
//TODO:  Pass command object
}
