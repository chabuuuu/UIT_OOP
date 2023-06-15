#include<iostream>
#include<vector>
#include<queue>
using namespace std;



class Server{
    private:
int id;
int ram;
float cpu;
int x;
int y;
    public:
void nhapThongTin(){
cin>>id>>ram>>cpu>>x>>y;
}
int getID(){
    return id;
}

float getWeight(){
    return cpu*ram;
}



};

class Request{
private:
int id;
int weight;
int x;
int y;
int serverManaged;
public:
void nhapThongTin(){
cin>>id>>weight>>x>>y;
}
void addServerManage(int idServer) {
    this->serverManaged = idServer;
}
int xuatThongTinServer(){
    return serverManaged;
}
int getWeight(){
    return weight;
}

};

class LoadBalancer{
protected:
    int id;
    int type;
    int x;
    int y;
    int nServer;
    int nLBChild;
    vector<LoadBalancer*> otherLB;
    vector<Server*> listServer;
public:
    LoadBalancer(){
        id = 0 ;
        type = 0;
        x = 0;
        y = 0;
        nServer = 0;
        nLBChild = 0;
    }

    LoadBalancer(int id, int type, int x, int y, int nServer, int nLBChild):
    id(id),
    type(type),
    x(x),
    y(y),
    nServer(nServer),
    nLBChild(nLBChild){}
    // void nhapThongTinLB() {
      
    // }
    virtual void chiaRequest(vector<Request*>) = 0;

    

    int getCountLBManaged(){
        return nLBChild;
    }

    void addServer (){
        Server* server;
        server->nhapThongTin();
        listServer.push_back(server);
    }
     void addLB (LoadBalancer* LB){
       
          otherLB.push_back(LB);
    }
    void xuatThongTin(){
        cout<<id<<type<<x<<y;
    }
   
};


class RoundroninLB : public LoadBalancer{
private:
public:
RoundroninLB(int id, int type, int x, int y, int nServer, int nLBChild):LoadBalancer(
    id, type, x, y, nServer, nLBChild){}

// void ganRequest(int countRequest, queue<Request*> listRequest, Server* server){
//     for (int i = 0 ; i < countRequest; i ++){
//         listRequest.front()->addServerManage(server->getID());
//         listRequest.pop();
//     }
// }

 void chiaRequest (vector<Request*> listRequest){
    int k = listRequest.size();
    int n = nLBChild + nServer;
    int countRequestPull  = ( k / n ) ;
    int countLastRequestPull = k - (n-1)*countRequestPull;
    int temp  = 0;
    if (nServer == 0){
        temp = 1;
    }
    for (int i = 0 ; i < nServer - temp ; i ++){
        // this->ganRequest(countRequestPull, listRequest, listServer[i]);
           for (int i = 0 ; i < countRequestPull; i ++){
        listRequest.front()->addServerManage(listServer[i]->getID());
        listRequest.erase(listRequest.begin());
    }
    }
    for (int i = 0 ; i < nLBChild - 1; i ++){
        otherLB[i]->chiaRequest(listRequest);
    }

    if (nServer == 0 ){
        for (int i = 0 ; i < countLastRequestPull; i ++){
        listRequest.front()->addServerManage(listServer.back()->getID());
        listRequest.erase(listRequest.begin());
    }
    }else{
        otherLB[nLBChild - 1]->chiaRequest(listRequest);
    }
    
}

};

class WeightroundroninLB : public LoadBalancer{
private:
public:
WeightroundroninLB(int id, int type, int x, int y, int nServer, int nLBChild):LoadBalancer(
    id, type, x, y, nServer, nLBChild){}




 void chiaRequest (vector<Request*> listRequest){
    int k = listRequest.size();
    int n = nLBChild + nServer;
    int countRequestPull  = ( k / n ) ;
    int countLastRequestPull = k - (n-1)*countRequestPull;
    int temp  = 0;
    if (nLBChild != 0){
        temp = 1;
    }
    vector<Server*> copyOfServer = listServer;
    int serverThichHop;
    //Với mỗi server
    int min = 9999;
    for (int i = 0 ; i < nServer - temp ; i ++){

        while (copyOfServer.empty() != true){

            for (int i = 0 ; i < copyOfServer.size(); i ++){
             for (int j = 0 ; j < countRequestPull; j ++){
            if ( min > abs(copyOfServer[i]->getWeight() - listRequest[j]->getWeight())){
                min = abs(copyOfServer[i]->getWeight() - listRequest[j]->getWeight());
                serverThichHop = i;
            }
        }
        }
        copyOfServer.erase(copyOfServer.begin() + serverThichHop);

        }


           


    }
    for (int i = 0 ; i < nLBChild - 1; i ++){
        otherLB[i]->chiaRequest(listRequest);
    }

    if (nServer == 0 ){
        for (int i = 0 ; i < countLastRequestPull; i ++){
        listRequest.front()->addServerManage(listServer.back()->getID());
        listRequest.erase(listRequest.begin());
    }
    }else{
        otherLB[nLBChild - 1]->chiaRequest(listRequest);
    }
    
}
};

class FasterReponseTimeLB : public LoadBalancer{
private:
public:
FasterReponseTimeLB(int id, int type, int x, int y, int nServer, int nLBChild):LoadBalancer(
    id, type, x, y, nServer, nLBChild){}
void chiaRequest (vector<Request*>){
    
   
}

};





static vector<LoadBalancer*> listLB;



class LoadBalancing{
private:
    //  vector<LoadBalancer*> listLB;
    int idLB;
    int typeLB;
    int xLB;
    int yLB;
    int nServer;
    int nLBChild;
    vector<Request*> listRequest;
    vector<Request*> copyOfRequest;
public:
    LoadBalancer* nhapThongTin(){
        LoadBalancer* LB;
        cin>>idLB;
        cin>>typeLB;
        cin>>xLB;
        cin>>yLB;
        cin>>nServer;
        cin>>nLBChild;
        switch (typeLB)
          {
          case 1:
            LB = new RoundroninLB(idLB, typeLB, xLB, yLB, nServer, nLBChild);
            break;
          case 2:
          LB = new WeightroundroninLB(idLB, typeLB, xLB, yLB, nServer, nLBChild);
          break;

          case 3:
          LB= new FasterReponseTimeLB(idLB, typeLB, xLB, yLB, nServer, nLBChild);
          break;

          default:
          LB = NULL;
          break;      
          }


        for (int i = 0 ; i <nServer; i++){
            LB->addServer();
        }
        for(int i = 0; i < nLBChild; i++){
            LoadBalancer* newLB;
            LoadBalancing newbalancing;
            newLB = newbalancing.nhapThongTin();
            listLB.push_back(newLB);
            LB->addLB(newLB);
            // delete newLB;
        }
        return LB;
    }
    void nhapRequest(){
        int nRequest;
        cin>>nRequest;
        for (int i = 0; i< nRequest; i++){
            Request* request;
            request->nhapThongTin();
            listRequest.push_back(request);
        }
        copyOfRequest = listRequest;
    }
    void pullRequest(LoadBalancer* LB){
        LB->chiaRequest(listRequest);
    }   

    void xuatKetQua(){
        for (int i = 0 ; i < copyOfRequest.size(); i ++){
            copyOfRequest[i]->xuatThongTinServer();
        }
    }
};


int main(){
    LoadBalancing a;
    LoadBalancer* LB;
    LB = a.nhapThongTin();
    a.nhapRequest();
   
}