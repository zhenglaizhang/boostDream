#include <iostream>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <sstream>

using namespace std;
using namespace boost::serialization;
using namespace boost::archive;

int main(int argc, char* argv)
{
	stringstream ss;
	{
		int i = 10;
		string str("monado"); 
		xml_oarchive oa(ss);
		//oa << make_nvp("ivalue", i) << make_nvp("svalue", str);
		oa << BOOST_SERIALIZATION_NVP(i)
			<< BOOST_SERIALIZATION_NVP(str);
	}
	{
		int i{};
		string str{};
		xml_iarchive ia(ss);
		//ia >> make_nvp("i", i) >> make_nvp("s", str);
		ia >> BOOST_SERIALIZATION_NVP(i)
			>> BOOST_SERIALIZATION_NVP(str);
		cout << i << ", " << str << endl;
	}

	cout << ss.str() << endl;

	cout << "hello" << endl;
}
