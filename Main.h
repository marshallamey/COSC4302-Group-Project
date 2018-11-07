#include <string>
#include <vector>

class Command {

public:
  Command();
  Command(std::string filename, std::vector<std::string> args);
  invoke(); //TODO:  Choose how failure is conveyed 
  std::string filename;
  std::vector<std::string> args;
}

Command::Command()
{
  filename = "";
}

//Alex
class Shell {
//TODO:  Determine command structure
//TODO:  Main loop structure (read print evaluate loop)
//TODO:  Pass command object
}
