using namespace std;

namespace inducing
{
    void execute_foo()
    {
        cout << "executing foo" << endl;
    }

    template <typename T>
    concept HasSize = requires(T t)
    {
        { t.size() } = std::convertible_to<std::size_t>;
    }

    template <HasSize T>
    void process(T a)
    {
        std::cout << a.size() << std::endl;
    }
}