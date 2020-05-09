#include<iostream>
using namespace std;

int maxSize = 10;

class SqListClass
{
    private:
        int *data;
        int length; 

    public:
        SqListClass();
        ~SqListClass();
        void CreateList(int a[], int n);
        void traversalLsit();
        bool Listinsert(int i, int x);
        bool Listdelete(int i);
};

SqListClass::SqListClass()
{
    data = new int[maxSize];
    length = 0;
}

SqListClass::~SqListClass()
{
    delete [] data;
}

void SqListClass::CreateList(int a[], int n)
{
    int i;
    for(i=0; i<n; i++) {
        data[i] = a[i];
    }
    length = i;
}

void SqListClass::traversalLsit()
{
    cout << "out:" << endl;
    for(int i = 0; i < length; i++) {
        cout << data[i] << "" << endl;
    }
}

bool SqListClass::Listinsert(int i, int x)
{
    if (i < 0 || i > length) return false;
    for (int j = length; j >= i; j--) {
        data[j] = data[j-1];
    }
    data[i-1] = x;
    length++;
    return true;    
}

bool SqListClass::Listdelete(int i)
{
    if (i < 0 || i > length) return false;
    for (int j = i-1; j < length; j++) {
        data[j] = data[j + 1];
    }
    length--;
    return true;
}

int main() {
    SqListClass SqList;
    int arr[4] = {1, 2, 3, 4};
    SqList.CreateList(arr, 4);
    SqList.traversalLsit();

    SqList.Listinsert(3, 9);
    SqList.traversalLsit();

    SqList.Listdelete(1);
    SqList.traversalLsit();
    return 0;
}