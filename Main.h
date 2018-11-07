#include <string>
#include <vector>

class Command {
  std::string filename;
  std::vector<std::string> args;
public:
  Command();
  Command(std::string filename, std::vector<std::string> args);
  invoke(); //TODO:  Choose how failure is conveyed 
}
//Alex
class Shell {
//TODO:  Determine command structure
//TODO:  Main loop structure (read print evaluate loop)
//TODO:  Pass command object
}
