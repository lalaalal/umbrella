#include "umbrella_handler.hpp"
#include "exceptions.hpp"

using namespace umbrella;

int main(int argc, char * argv[]) {
    try {
        UmbrellaHandler umbrellaHandler = UmbrellaHandler();
        
    } catch (Exception & e) {
        e.print();
    } catch (sql::SQLException & e) {
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }

    return 0;
}
