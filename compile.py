import os
import logging



def build_mycpplint():
    command = "cpplint --quiet "
    all_src_files_wildcard = get_chess_src_path() + '*pp' # wildcard to get hpp/cpp
    return command + all_src_files_wildcard

def get_chess_src_path():
    """Returns the path of the chess src directory as a string"""
    home = os.path.expanduser("~")
    return os.path.join(home, "chess", "src", "") # empty string will add / at end


def get_chess_build_path():
    """Returns the path of the chess build directory as a string"""
    home = os.path.expanduser("~")
    return os.path.join(home, "chess", "build", "") # empty string will add / at end


def build_gcc_compile_obj():
    """Builds the command: g++ -c <.cpp files> command """
    home = os.path.expanduser("~")
    command = "g++ -g -Wall -c "
    src_files = os.listdir(get_chess_src_path())
    cpp_extension = ".cpp"
    cpp_files = [file for file in src_files if cpp_extension in file]
    space_sep_cpps = ' '.join(map(str,cpp_files))
    space_sep_cpps = space_sep_cpps.replace(' ', ' ' + get_chess_src_path())
    space_sep_cpps = get_chess_src_path() + space_sep_cpps
    command = command + space_sep_cpps
    return command


def build_gcc_chess_exe():
    """Builds the command: g++ <.o files> -o chess <includes>"""
    command = "g++ -g -Wall "
    build_files = os.listdir(get_chess_build_path())
    o_extension = ".o"
    o_files = []
    for build_file in build_files:
        if build_file.endswith(o_extension):
            o_files.append(build_file)
    space_sep_os = ' '.join(map(str, o_files))
    command = command + space_sep_os + " -o chess "
    includes = "-lsfml-graphics -lsfml-window -lsfml-system"
    command = command + includes
    return command


def main():
    logging.basicConfig(filename = 'chessCompile.txt')
    build_dir = os.path.join(os.getcwd(), 'build')
    if not os.path.exists(build_dir):
        os.mkdir(build_dir)

    os.chdir(build_dir)
    #retval = os.system(build_mycpplint())
    #if retval:
    #    logging.error("cpplint src_dir/*pp has failed. Are there files at %s?"
    #                  % get_chess_src_path())
    #else:
    #    logging.info("cpplint src_dir/*pp command was successful")

    gcc_compile_cmd = build_gcc_compile_obj() 
    retval = os.system(gcc_compile_cmd)
    if retval:
        logging.error("g++ -c <files> has failed. Are there cpp files at %s?"
                      % get_chess_src_path())
    else:
        logging.info("g++ -c <files> command was successful")
    
    retval = os.system(build_gcc_chess_exe())
    if retval:
        logging.error("g++ <o_files> -o chess <includes> has failed. Are the files in %?"
                      % get_chess_build_path())
    else:
        logging.info("g++ -c <files> command was successful")


if __name__ == '__main__':
    main()


