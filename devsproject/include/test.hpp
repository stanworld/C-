using namespace std;
class test{
public:
test() {
    cout<<"this is test "<<endl;
}
test(int i) {
    cout<< "this is test " << i <<endl;
}

virtual ~test() {
   cout<<"this is test deconstructor()" <<endl;
}

};

class mytest: public test {
    public:
    mytest() {
        cout<< "this is my test"<<endl;
    }
    mytest(int i) {
        cout<< "this is my test " <<i <<endl;
    }

    ~mytest() {
        cout<< "this is my test deconstructor() "<<endl;
    }
};
