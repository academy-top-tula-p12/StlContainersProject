#include <iostream>
#include <array>
#include <vector>
#include <forward_list>
#include <typeinfo>

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

    //users.sort(HeightComparer);
    users.sort([](User u1, User u2) -> bool
        {
            return u1.Height() < u2.Height();
        });

    std::cout << "\n";
    for (auto u : users)
        std::cout << u.Name() << " " << u.Age() << " " << u.Height() << "\n";
    std::cout << "\n";
}
