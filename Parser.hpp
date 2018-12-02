#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "Command.hpp"

/*
* Quoting "$ man execv"
 *     The  execlp(),  execvp(), and execvpe() functions duplicate the actions
 *     of the shell in searching for an executable file if the specified file‐
 *     name does not contain a slash (/) character.  The file is sought in the
 *     colon-separated list of directory pathnames specified in the PATH envi‐
 *     ronment  variable.   If  this  variable  isn't  defined,  the path list
 *     defaults to the current directory followed by the list  of  directories
 *     returned by confstr(_CS_PATH).  (This confstr(3) call typically returns
 *     the value "/bin:/usr/bin".)
 *
 *     If the specified filename includes a  slash  character,  then  PATH  is
 *     ignored, and the file at the specified pathname is executed.
 */

std::vector<std::string> tokenize(const std::string& document, const std::string& delimiters);

std::string path_resolver(const std::string& program_name);

Command make_command(const std::string& document);

#endif // PARSER_H
