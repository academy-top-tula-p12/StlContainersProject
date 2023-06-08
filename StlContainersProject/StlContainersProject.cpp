#include <iostream>
#include <array>
#include <vector>
#include <forward_list>
#include <typeinfo>
#include <list>
#include <set>
#include <map>
#include <unordered_set>

class User
{
    std::string name;
    int age;
    int height;
public:
    std::string& Name() { return name; }
    int& Age() { return age; }
    int& Height() { return height; }

    User(std::string name, int age, int height) 
        : name{ name }, age{ age }, height{ height } {}

    friend bool operator<(User u1, User u2);
};

bool operator<(User u1, User u2)
{
    return u1.name < u2.name;
}

class UserAgeComparer
{
public:
    bool operator()(User u1, User u2)
    {
        return u1.Age() < u2.Age();
    }
};

bool HeightComparer(User u1, User u2)
{
    return u1.Height() < u2.Height();
}

int main()
{
    // std::array
    /*
    std::array<int, 10> arr2;
    arr2.fill(5);
    */

    // std::vector
    /*
    std::vector<float> v0 { 7, 4, 6, 9, 11, 2, 8, 1, 17, 5 };
    //std::vector<int> v1(10, 5);
    std::vector<int> v1(v0.begin() + 2, v0.end() - 3);

    for (auto item : v1)
        std::cout << item << " ";
    std::cout << "\n";
    */

    // std::forward_list
    /*
    std::forward_list<int> flist = { 5, 11, 7, 9, 2, 21, 16 };
    flist.sort();

    for (auto item : flist)
        std::cout << item << " ";
    std::cout << "\n";

    std::forward_list<User> users =
    {
        User("Tim", 34, 168),
        User("Leo", 21, 179),
        User("Bob", 43, 172),
        User("Tom", 29, 166),
        User("Jim", 19, 180)
    };

    auto it = users.begin();
    for (int i = 0; i < 2; i++, it++);

    User joe("Joe", 25, 177);
    users.insert_after(it, joe);

    std::cout << "\n";
    for (auto u : users)
        std::cout << u.Name() << " " << u.Age() << " " << u.Height() << "\n";
    std::cout << "\n";

    //users.sort(HeightComparer);
    users.sort([](User u1, User u2) -> bool
        {
            return u1.Height() < u2.Height();
        });

    std::cout << "\n";
    for (auto u : users)
        std::cout << u.Name() << " " << u.Age() << " " << u.Height() << "\n";
    std::cout << "\n";
    */

    //std::list
    /*
    std::list<int> list1;

    std::vector<int> v1{ 6, 3, 9, 2, 6, 5, 10, 1 };
    std::list<int> list2(v1.begin() + 1, v1.end() - 2);

    for (auto item : list2) std::cout << item << " ";
    std::cout << "\n";

    std::list<int> list3 { 2, 7, 3, 9, 4 };

    std::cout << list3.max_size() << "\n";

    list3.insert(++list3.begin(), v1.begin() + 2, v1.end() - 2);
    list3.insert(++list3.begin(), { 11, 54, 23 });
    for (auto item : list3) std::cout << item << " ";
    std::cout << "\n";


    std::list<int> list5 { 1, 2, 3, 4, 5 };
    std::list<int> list6 { 11, 22, 33, 44, 55 };

    list5.splice(++list5.begin(), list6, ++list6.begin(), --list6.end());
    for (auto item : list5) std::cout << item << " ";
    std::cout << "\n";

    list5.remove_if([](auto item) { return item % 2; });
    for (auto item : list5) std::cout << item << " ";
    std::cout << "\n";


    std::list<int> list7 { 1, 1, 2, 3, 4, 2, 2, 4, 3, 4, 3 };
    for (auto item : list7) std::cout << item << " ";
    std::cout << "\n";

    list7.sort();
    list7.unique();

    for (auto item : list7) std::cout << item << " ";
    std::cout << "\n";
    */

    //std::set
    /*
    std::set<int> setInt1 { 1, 2, 3, 4, 5, 6, 7, 8 };

    for (auto item : setInt1) std::cout << item << " ";
    std::cout << "\n";

    std::set<int> setInt2 { 5, 6, 7, 8, 9, 10, 11, 12 };

    for (auto item : setInt2) std::cout << item << " ";
    std::cout << "\n";

    setInt1.merge(setInt2);
    for (auto item : setInt1) std::cout << item << " ";
    std::cout << "\n";
    * /

    /*std::set<User, UserAgeComparer> setUsers;
    setUsers.emplace("Kim", 28, 181);*/
    /*
    std::set<int> setBound { 1, 3, 5, 6, 7 };
    for (auto item : setBound) std::cout << item << " ";
    std::cout << "\n";

    std::cout << *setBound.lower_bound(2) << "\n";
    std::cout << *setBound.lower_bound(3) << "\n";
    std::cout << *setBound.upper_bound(2) << "\n";
    std::cout << *setBound.upper_bound(3) << "\n";

    std::set<std::pair<int, std::string>> regions
    {
        {71, "Tula"},
        {38, "Irkutsk"},
        {77, "Moscow"},
        { 38, "Irkutsk" },
    };

    for (auto item : regions)
        std::cout << item.first << " " << item.second << "\n";
    std::cout << "\n";
    */
    // map
    std::map<int, std::string> regions{
        {71, "Tula"}
    };
    regions[71] = "Tulskaya oblast";

    std::map<std::string, std::string> countries
    {
        {"Russia", "Moscow"},
        {"Usa", "Washingthon"}
    };

    std::unordered_set<std::string> names
    {
        "Sam", "Ben", "Leo", "Joe", "Tim", "Neo"
    };

    auto hash = names.hash_function();

    for (auto item : names) std::cout << item << " " << hash(item) << "\n";
    std::cout << "\n";
}
