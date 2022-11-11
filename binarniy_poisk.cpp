#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <algorithm>

using namespace std;

void ArrayInput(array<int, 10> &mas)
{
    for (int i = 0; i < mas.size(); i++)
    {
        mas[i] = rand()%10;
        cout << mas[i] << "\t";
    }
    cout << endl;
}

int KeyINput()
{
    int value;
    cin >> value;
    return value;
}

bool BinarySearch(array<int, 10> &arr, int key)
{
    int l = 0, r = 10, mid;
    bool flag = false;
    while ((l <= r) && (flag != true)) {
        mid = (l + r) / 2;
        if (arr.at(mid) == key) 
            flag = true;
        if (arr.at(mid) > key) 
            r = mid - 1;
        else l = mid + 1;
    }
    return flag;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");
    srand(static_cast<unsigned int>(time(0)));
    
    array <int, 10> mas;
    ArrayInput (mas);
    
    sort(mas.begin(), mas.end());
    
    int key = KeyINput();
    
    if (BinarySearch (mas, key))
        cout << "элемент найден\n";
    else 
        cout << "данного элемента нет\n";
    
    return 0;
}

