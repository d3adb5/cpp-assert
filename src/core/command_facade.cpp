#include "../../include/core/command_facade.hpp"

namespace command_facade
{
    CommandMap commands = {
        { "self_test", []() -> void { self_test(); } },
        { "test",      []() -> void { test(); } }
    };

    std::function<void()> parse(string const &command)
    {
        auto it = commands.find(command);

        auto notfound = [command]() -> void {
            std::cerr << "Command '" << command << "' not found." << std::endl;
        };

        return (it != commands.end()) ? it->second : notfound;
    }

    std::vector<std::string> list_commands()
    {
        std::vector<std::string> keys;

        keys.reserve(commands.size());

        for (auto it = commands.begin(); it != commands.end(); ++it)
            keys.push_back(it->first);

        return keys;
    }

    void self_test()
    {
        Runner *runner = Runner::get_instance();
        vector<string> tests = {Constants::ASSERT_TEST};

        runner->process(tests);
        runner->run(tests);

        assert::show_statistics();
    }

    void test()
    {
        Scanner *scanner = Scanner::get_instance();
        Runner *runner = Runner::get_instance();

        vector<string> tests = scanner->scan_test_folder();

        runner->process(tests);
        runner->run(tests);

        assert::show_statistics();
    }
}
