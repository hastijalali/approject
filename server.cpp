#include <iostream>
#include <string>
#include "httplib.h"
#include "header.h"
using namespace std;
using namespace httplib;
int main(){
    Server srv;
    srv.Post("/runserver",[&](const auto & req , auto &res){
        res.set_content("client is connected", "text/plain");
        const auto& file = req.get_file_value("Start");
        string pl1 = file.filename;
        string pl2 = file.content_type;
        cout<<pl1<<"\n"<<pl2<<"\n";

    });
    cout<<"start server"<<endl;
    srv.listen("127.0.0.1",8000);
}