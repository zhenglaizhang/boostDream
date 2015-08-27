#include <iostream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace boost::uuids;

int main()
{
	uuid u = random_generator()();
	std::cout << u << std::endl;
	std::cout << u.size() << std::endl;
	std::cout << u.version() << std::endl;
}