class DaThucBatHai{
private:
float a;
float b; 
float c;




public:
float tinhGiaTri(float x){
return a*x*x + b*x + c;
}
DaThucBatHai operator+(DaThucBatHai daThucB){
DaThucBatHai res;
res.a = this->a + daThucB.a;
res.b = this->b + daThucB.b;
res.c = this->c + daThucB.c;
return res;
}
};
