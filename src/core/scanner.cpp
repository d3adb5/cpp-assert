
#include "../../include/core/constants.hpp"
#include "../../include/core/scanner.hpp"
#include "../../include/types.hpp"

vector<string> Scanner::scan_test_folder()
{
    Path path = fs::current_path();
    Directories directory_iterator = fs::recursive_directory_iterator(path);

    vector<string> tests;

    for (const Entry &entry : directory_iterator)
    {
        string file = entry.path();
        if (file.find(CoreConstants::TEST_FOLDER) != string::npos)
        {
            tests.push_back(parse_header(file));
        }
    }

    return tests;
}

String Scanner::parse_header(string const &unit_test_header)
{
    const int path_prefix = unit_test_header.find(CoreConstants::TEST_FOLDER);
    const String base = unit_test_header.substr(path_prefix + CoreConstants::TEST_FOLDER.length());
    const int extension_position = base.find(".");
    return base.substr(0, extension_position);
}