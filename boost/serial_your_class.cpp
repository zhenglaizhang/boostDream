#include <iostream>
#include <sstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/access.hpp>
class Persion
{
public:
	Persion() = default;
	Persion(int id, const std::string& l, const std::string& r)
		: id(id), firstName(l), lastName(r){};
	~Persion() {};

	friend bool operator==(const Persion& l, const Persion& r);

private:
	friend boost::serialization::access;
	template <typename Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar & id & firstName & lastName;
	}

	int id;
	std::string firstName, lastName;
};

bool operator==(const Persion& l, const Persion& r)
{
	return l.id == r.id && l.firstName == r.firstName && l.lastName == r.lastName;
}

int main()
{
	using namespace std;
	using namespace boost::serialization;
	using namespace boost::archive;
	stringstream ss;
	Persion p1(12, "Zhenglai", "Zhang");
	text_oarchive(ss) << p1;
	cout << ss.str() << endl;

	Persion p2;
	text_iarchive(ss) >> p2;
	cout << (p1 == p2) << endl;;
	
}