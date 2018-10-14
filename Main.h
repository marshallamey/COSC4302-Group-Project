#include <string>
#include <vector>

class Command {
  std::string filename;
  std::vector<std::string> args;
public:
  Command(std::string filename, std::vector<std::string> args);
  invoke();
}

class Shell {

}
