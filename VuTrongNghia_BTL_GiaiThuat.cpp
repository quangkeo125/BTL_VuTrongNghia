#include<bits/stdc++.h>
using namespace std;

//===Quan Ly dau sach(Danh sach lien ket don)===

struct SACH
{
	int maSach;	
	char tenSach[100];	
	float donGia;
	float tienThue;	
};

//ds lk don

struct Node
{
	SACH info;
	struct Node*next;
};

struct List
{
	Node *Head;
	Node *Tail;
};
//khoi tao ds rong
void KhoiTao(List &Q)
{
	Q.Tail=NULL;
	Q.Head=NULL;
}
//tao nut chua thong tin sach
Node *getNode(SACH x)
{
	Node *pSach;
	pSach=new Node;
	if(pSach==NULL)
	{
		cout<<"cap phat loi"<<endl;
		return 0;
	}
	pSach->info=x;
	pSach->next=NULL;
	return pSach;
}
//them sach vao cuoi danh sach
void insertLast(List &Q, Node *pSach)
{
	if(Q.Head==NULL)
	{
		Q.Head=pSach;
		Q.Tail=Q.Head;
	}
	else 
	{
		Q.Tail->next=pSach;
		Q.Tail=pSach;
	}
}
void nhapSach(SACH &x)
{
	cout<<"nhap ma sach:"; cin>>x.maSach;
	fflush(stdin);
	cout<<"Nhap ten sach: "; gets(x.tenSach);
	cout<<"Nhap don gia: "; cin>>x.donGia;
	x.tienThue = x.donGia/2;
}
void nhapDSSach(List &Q)
{
	int n;
	Node *pSach;
	SACH x;
	cout<<"nhap so dau sach: ";
	cin>>n;
	for (int i=0;i<n;i++)
	{
		nhapSach(x);
		pSach=getNode(x);
		insertLast(Q,pSach);
	}
	
}

void xuatSach(SACH x)
{
	cout<<setw(18)<<left<<x.maSach<<"\t";
	cout<<setw(12)<<left<<x.tenSach<<"\t";
	cout<<setw(7)<<left<<x.donGia<<"\t";
	cout<<setw(10)<<left<<x.tienThue<<"\t";
	cout<<endl;
	
}
void xuatDSSach(List &Q)
{
	Node*pSach;
	cout<<"danh sach hien co:"<<endl;
	cout<<setw(15)<<left<<"Ma Sach"<<"\t";
	cout<<setw(12)<<left<<"Ten Sach"<<"\t";

	cout<<setw(10)<<left<<"Don Gia"<<"\t";
	cout<<setw(15)<<left<<"Gia Thue Sach"<<"\t";
	cout<<endl;
	for(pSach=Q.Head;pSach!=NULL;pSach=pSach->next)
	   xuatSach(pSach->info);
}


//tim lkien
Node *search(List &Q, int k)
{
	Node *pSach;
	for (pSach=Q.Head;pSach!=NULL;pSach=pSach->next)
	    if (pSach->info.maSach==k) break;
	    return pSach;
}
void sapXepTheoDonGia(List &Q)
{
	Node *pSach, *q;
	SACH tg;
	for(pSach=Q.Head;pSach!=NULL;pSach=pSach->next)
	   for (q=pSach->next;q!=NULL;q=q->next)
	     if (pSach->info.donGia > q->info.donGia)
	       {
	       	tg=pSach->info;
	      	pSach->info=q->info;
	      	q->info=tg;
		   }   
}
//chưa sửa
// void ThongKe(List &Q, char quyMo[]){
// 	Node *pNDT;
// 	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
// 		if (strcmp(pNDT->info.quyMo,quyMo)==0){
// 			xuatNDT(pNDT->info);
// 		}
// }
//chưa sửa
// void Sapxepdiachi(List &Q){
// 	Node *pNDT, *q;
// 	NGUOIDONGTHUE tg;
// 	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
// 	   for (q=pNDT->next;q!=NULL;q=q->next)
// 	     if (strcmp(pNDT->info.diaChi, q->info.diaChi)>0)
// 	       {
// 	       	tg=pNDT->info;
// 	      	pNDT->info=q->info;
// 	      	q->info=tg;
// 		   } 
// 		  xuatDSNDT(Q);  
// }
//xoa theo ma sach

void Remove(List &Q, int ma)
{
	Node *pSach=Q.Head, *q=NULL;
	while(pSach!=NULL){
		if(pSach->info.maSach==ma) break;
		q=pSach;
		pSach=pSach->next;	
	}
	if(pSach==NULL) cout<<"Khong tim thay ma"<<endl;
	if(q!=NULL)
	{
		if(q==Q.Tail) 
		Q.Tail=q;
		q->next=pSach->next;
		delete pSach;
	}
	else
	{
		Q.Head=pSach->next;
		if(Q.Head==NULL) Q.Head=NULL;
	}
	cout<<"Xoa thanh cong"<<endl;
}

//cho biet Cong ty co dia chi tai x

void timTenSach(List &Q, char x[])
{
	Node*pSach;
	cout<<"Thong tin dau sach "<<x<<" la:"<<endl;
	for(pSach=Q.Head;pSach!=NULL;pSach=pSach->next)
	if (strcmp(pSach->info.tenSach,x)==0)
	xuatSach(pSach->info);
	cout<<endl;
}

void donGiaMax(List &Q){
	Node *pSach;
	float max=-1;
	for(pSach=Q.Head;pSach!=NULL;pSach=pSach->next)
		if(max < pSach->info.donGia)
		 max=pSach->info.donGia;
	for(pSach=Q.Head;pSach!=NULL;pSach=pSach->next)
	if(pSach->info.donGia==max)
	xuatSach(pSach->info);
}

void Sua(List &Q) {
	Node *pSach,*qSach,*m;
	SACH x;
	int maSach;
	int maflag = 0;
	cout<<"Nhap ma sach can sua: "; cin>>maSach;
	for(pSach=Q.Head;pSach!=NULL;pSach=pSach->next) {
		if(pSach->info.maSach==maSach) {
			qSach=pSach;		
			maflag = maSach;
			}
		}
	if (maflag==0)
	{
		cout<<"Ma sach khong ton tai"<<endl;

	} else {
		for(pSach=Q.Head;pSach!=NULL;pSach=pSach->next)
		if(pSach->next==qSach){
			m=pSach;
		}
	        nhapSach(x);
			Node *q=getNode(x);
			if(m->next==NULL){
				Q.Tail->next=q;
				Q.Tail=q;
			}else{
			Node *h= getNode(q->info);
			Node *tg =m->next;
			h->next=tg;
			m->next=h;
			}
	Remove(Q,maSach);
	xuatDSSach(Q);
	
	
	}
	
	
		
}



void chenphantusauma(List &Q) {
	Node *p, *q;
	int maChen,dem=0;
	SACH x;
	cout<<"Nhap ma can chen: "; cin>>maChen;
	for(p=Q.Head;p!=NULL;p=p->next)
			if(p->info.maSach==maChen){
			dem++;
			nhapSach(x);
			q=getNode(x);
			if(p->next==NULL){
				Q.Tail->next=q;
				Q.Tail=q;
			}else{
				Node *h=getNode(q->info);
				Node *k=p->next;
				h->next=k;
				p->next=h;
			}
		}
	if(dem==0) cout<<"Khong tim thay ma"<<endl;
	xuatDSSach(Q);
	
}
//Luu file
void Luufile(FILE *f, List &Q, char *name)
{
	f=fopen(name,"w+b");
	int n=0;
	Node *pNDT;
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
	{
	n=n+1;
	}
	fwrite(&n,sizeof(int),1,f);
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next){
	fwrite(&pNDT->info,sizeof(SACH),1,f);
	}
	fclose(f);
	cout<<"Ghi file thanh cong"<<endl;
}


void DocFile(FILE *f, List &Q, char *name)
{
	SACH x;
	int i,n;
	Node *pNDT;
	KhoiTao(Q);
	f=fopen(name,"r+b");
	if(f==NULL)
	{
		cout<<"Mo tep khong thanh cong"<<endl;
		return;
	}
	cout<<"Bat dau doc file"<<endl;
	fread(&n,sizeof(int),1,f);
	for(i=0;i<n;i++)
	{
		fread(&x,sizeof(SACH),1,f);
		pNDT=getNode(x);
		insertLast(Q,pNDT);
	}
	fclose(f);
	cout<<"Doc file thanh cong"<<endl;
	xuatDSSach(Q);
}

//===Quan Ly Phieu Thu Thue(Danh sach lien ket doi)===

using namespace std;
struct phieuthu {
	int mapt;
	string ngaymuon, mssv, hotennguoinop, maSach;
	// float tongtien, sotiengiam, sotiencandong;	
};


struct NodePT{
	phieuthu info;
	struct NodePT*next; 
	struct NodePT*prev;
};


struct LISTPT{
	NodePT*Head;
	NodePT*Tail;
};


LISTPT PT;
void khoitaoPT ( LISTPT & PT )
{
	PT.Head = NULL;
	PT.Tail = NULL;
}

NodePT * GetNode( phieuthu x  )
{
	NodePT *p;
	p = new NodePT();
	if (p == NULL)
{
	cout<<("Ko du bo nho");
	exit(1);
}
	p -> info = x;
	p -> next = NULL;
	p -> prev = NULL;
	return p;
} 


void chencuoipt( LISTPT & PT, NodePT *p )
{
if ( PT.Head == NULL ) //n�u danh s�ch r�ng
{
PT.Head = p;
PT.Tail = PT.Head;
}
else //danh s�ch kh�ng r�ng
{
PT.Tail->next=p;
p->prev=PT.Tail;
PT.Tail=p;
}
}
void nhappt ( phieuthu &x){
	cout<<"\n Ma phieu thu: ";
	cin>>x.mapt;
	cout<<"\n Ma so sinh vien: ";
	cin>>x.mssv;
	cout<<"\n Ho ten nguoi nop: ";
	cin.ignore();
	getline(cin,x.hotennguoinop);
	cout<<"\n Ma sach: ";
	cin>>x.maSach;
	cout<<"\n Ngay muon: ";
	cin.ignore();
	getline(cin, x.ngaymuon);	
}

void nhapdspt ( LISTPT & PT){
	int n;
	NodePT * p;
	phieuthu x;
	cout <<" Nhap so phieu thu: "; cin>>n;
	for (int i=1 ; i<=n ; i++)
	{
		nhappt (x);
		p = GetNode(x); 
		chencuoipt( PT, p);
		}
		
}


void xuatpt ( phieuthu x){
	cout<<"\n"<<setw(5) << x.mapt;
	cout<<setw(15)<< x.mssv;
	cout<<setw(15)<< x.hotennguoinop;
	cout<<setw(15)<< x.maSach;
	cout<<setw(15)<< x.ngaymuon;
	cout<<endl;
}


void xuatdspt ( LISTPT & PT){
	cout<<"\n Danh sach phieu thu hien co: \n"<<endl;
	cout<<"\n"<<setw(8) << "Ma pt";
	cout<<setw(15)<< "MSSV";
	cout<<setw(20)<< "Ho ten sinh vien";
	cout<<setw(15)<< "Ma sach";
	cout<<setw(15)<< "Ngay muon"<<endl;
	for ( NodePT *p = PT.Head; p!= NULL;p = p->next)
	xuatpt( p->info);	
}
NodePT * timmapt ( LISTPT &PT, int mpt ){
	NodePT *p;
	for (p=PT.Head; p!=NULL; p=p->next)
	if (p->info.mapt == mpt)
	break;
	return p;
}
void sapxeppt(LISTPT PT){
	NodePT *p;
	NodePT *q;
	phieuthu tg;
	cout<<"\n Sap xep theo ma so sinh vien:";
	for(p = PT.Head; p!=NULL; p=p->next)
	for(q=p->next ; q!=NULL ; q=q->next){
		if(p->info.mssv<q->info.mssv)
		{
			tg=p->info;
			p->info=q->info;
			q->info=tg;
		}
	}
	xuatdspt(PT);	
}
void luuf(LISTPT PT, char* filename){
	FILE *f;
	f=fopen(filename,"w+b");
	for (NodePT *p= PT.Head; p != NULL; p = p->next){
		fwrite(&p->info,sizeof(phieuthu),1,f);
}
			fclose(f);
	FILE *t;
	t=fopen("Ten FILE","a+b");
	fwrite(&filename,sizeof(filename),1,t);
	cout<<"Da luu vao: "<<filename<<endl;
	fclose(t);


}
void docf(LISTPT PT, char* filename){
	khoitaoPT(PT);
	FILE *f;
	phieuthu x;
	NodePT*p;
	// cout<<"Mo file:\nCac FILE da luu:"<<endl;
	// char Ten[20];
	// FILE *t;
	// int i=0;
// 	t=fopen("Ten FILE","r+b");
// while(true)
//  {
//  if(t == NULL){ fclose(t);
// break; 
// }
//  	fread(&Ten ,sizeof(Ten),1,t);
//  	if(feof(t))break;
//  	i++;
//  	cout<<"File "<<i<<": "<<Ten<<endl;
//  	}
//  	fclose(t);
// 	cout<<"Nhap ten FILE muon mo: ";fflush(stdin);gets(filename);
	f=fopen(filename,"r+b");
if(f == NULL)
 {
	 cout<<"\nLoi mo tep";
	 return;
 	}
 	while(true)
 	{
 	fread(&x ,sizeof(phieuthu),1,f);
 	if(feof(f))break;
 	p=GetNode(x);
 	chencuoipt(PT,p);
 	}

 while(!feof(f));
 
 	fclose(f);
 	cout<<"Danh sach trong file "<<filename<<" la:"<<endl;
 	xuatdspt(PT);
}


void DocFilePT(LISTPT PT, char* filename)
{
	FILE *f;
	phieuthu x;
	int i,n;
	NodePT *pNDT;
	khoitaoPT(PT);
	f=fopen(filename,"r+b");
	if(f==NULL)
	{
		cout<<"Mo tep khong thanh cong"<<endl;
		return;
	}
	cout<<"Bat dau doc file"<<endl;
	fread(&n,sizeof(int),1,f);
	for(i=0;i<n;i++)
	{
		fread(&x,sizeof(phieuthu),1,f);
		pNDT=GetNode(x);
		chencuoipt(PT,pNDT);
	}
	fclose(f);
	cout<<"Doc file thanh cong"<<endl;
	xuatdspt(PT);
}

void XoaNodeDau(LISTPT &PT){	
	if (PT.Head != NULL) {
			NodePT *p = PT.Head; 
			PT.Head = PT.Head->next;
			PT.Head->prev=NULL;
			delete p;
			cout<<"Danh sach sau khi xoa phan tu dau tien: \n";
			xuatdspt(PT);
	}
	if(PT.Head==NULL) {
		cout<<"Danh sach rong"<<endl;
			khoitaoPT(PT);
	}



}

void XoaNodeCuoi(LISTPT &PT){
	if (PT.Head->next == NULL) {
		XoaNodeDau(PT);
		}
	for (NodePT *p = PT.Head; p != NULL; p = p->next) {
		if (p->next == PT.Tail) {
			delete PT.Tail;
			p->next = NULL; 
			PT.Tail = p; 
			}
		}
}

void XoaNodeCoKhoaBatKy (LISTPT &PT,int xoa ){
	 NodePT *p;
	p = timmapt (PT,xoa); //T�m ki?m ph?n t? d? x�a
	if ( p == NULL ){
		cout<<"Khong tim thay phan tu can xoa"<<endl;
	} else {
		if ( ( p == PT.Head ) && ( p == PT.Tail) ) { 
			PT.Head = NULL; PT.Tail = NULL;
			} else if ( p == PT.Head ) PT.Head = p->next;
			else if ( p == PT.Tail ) PT.Tail = p -> prev;
			else {
			p -> prev -> next = p -> next;
			p -> next -> prev = p -> prev;
			}
		free(p);
		cout<<"Danh sach sau khi xoa: ";
		xuatdspt(PT);
	}
}



int main()
{
	List Q;
	Node *pSach;
	int k,chon,luachon,choose;
	KhoiTao(Q);
	FILE *f;
	NodePT *p;
	khoitaoPT(PT);
	char filename[20] = "dausach.txt" ;
	char filename2[20] = "phieuthu.txt";
	do{
		cout<<"\t|1.Quan Ly Dau Sach "<<endl;
		cout<<"\t|2.Quan Ly Phieu Thu "<<endl;
		cout<<"\t|0.Thoat "<<endl;
		cout<<"Xin moi chon: ";
		cin>>luachon;
		switch(luachon)
		{
			case 1: {
						do{
						cout<<"\t|1.Nhap danh sach dau sach "<<endl;
						cout<<"\t|2.In danh sach dau sach "<<endl;
						cout<<"\t|3.Tim kiem theo ma dau sach "<<endl;
						cout<<"\t|4.Sap xep theo don gia "<<endl;
						cout<<"\t|5.Xoa dau sach theo ma "<<endl;
						cout<<"\t|6.Tim dia chi "<<endl;
						cout<<"\t|7.Luu File "<<endl;
						cout<<"\t|8.Doc File "<<endl;
						cout<<"\t|9.Tim sach co don gia lon nhat "<<endl;
						cout<<"\t|10.Sua dau sach "<<endl;
						cout<<"\t|11.Chen dau sach sau ma nao do "<<endl;
						cout<<"\t|0.Quay lai "<<endl;
						cout<<"\t|Chon: ";
						cin>>chon;
						switch(chon)
						{
							case 1: nhapDSSach(Q);
									Luufile(f,Q,filename); 
									break;
							case 2: xuatDSSach(Q); break;
							case 3:
							cout<<"Nhap ma dau sach can tim: "; cin>>k;
							pSach=search(Q,k);
							if (pSach==NULL)
							{
								cout<<"Khong tim thay"<<endl;
							} else {
								cout<<"Tim thay"<<endl;
								xuatSach(pSach->info);
							 } 
						     break;
							case 4: sapXepTheoDonGia(Q); xuatDSSach(Q); 
									Luufile(f,Q,filename); break;
							case 5: int ma;
									cout<<"Nhap ma dau sach can xoa: "; cin>>ma;
									Remove(Q,ma); xuatDSSach(Q); 
									Luufile(f,Q,filename); break;
							case 6: char x[20];
									fflush(stdin);
									cout<<"Nhap ten sach can tim: "; gets(x);
									timTenSach(Q,x);
									break;
							case 7: Luufile(f,Q,filename); break;
							case 8: DocFile(f,Q,filename); break;
							case 9: donGiaMax(Q); break;
							case 10: Sua(Q);
								break;
							case 11: chenphantusauma(Q); 
								Luufile(f,Q,filename);
								break;
							case 0: break;
						
						}
						
					}while(chon!=0);
				break;
			}
			case 2: {
						do{
						cout<<"\t 1. Nhap danh sach phieu thu"<<endl;
						cout<<"\t 2. In phieu thu"<<endl;
						cout<<"\t 3. Tim kiem phieu thu theo ma: "<<endl;
						cout<<"\t 4. Sap xep phieu thu theo don gia giam dan:"<<endl;
						cout<<"\t 5. Xoa phieu thu theo ma: "<<endl;
						cout<<"\t 6. Xoa phieu thu dau tien: "<<endl;
						cout<<"\t 7. Xoa phieu thu cuoi cung: "<<endl;
						cout<<"\t 8. Luu file: "<<endl;
						cout<<"\t 9. Doc file: "<<endl;
						cout<<"\t 0. Thoat"<<endl;
						cout<<"\t Chon: ";
						cin>>choose;
						switch(choose)
						{
							case 1: nhapdspt(PT); break;
							case 2: xuatdspt(PT);break;
							case 3:
								{
								cout<<"\n Nhap ma can tim: ";
								cin>>k;
								p= timmapt(PT, k);
								if ( p== NULL)
								cout<<"\n Khong tim thay";
								else {
									cout<<"\n Phieu thu can tim la";
									cout<<"\n"<<setw(10) << "Ma pt";
									cout<<setw(10)<< "MSSV";
									cout<<setw(10)<< "Ho ten sinh vien";
									cout<<setw(10)<< "Ma sach";
									cout<<setw(10)<< "Ngay muon";
									xuatpt (p->info);									
									}
								}
								break;
								case 4: 
										{
									cout<<"Danh sach phieu thu da sap xep:";
									sapxeppt(PT);
									cout<<"\n";
									}
								break;
								
								case 5: 
								int xoa;
								cout<<"Nhap ma phieu thu can xoa: ";
								cin>>xoa;
								XoaNodeCoKhoaBatKy(PT,xoa);
								break;
								
								case 6: {
								XoaNodeDau(PT);
								
								}
								break;
								
								case 7:{
									XoaNodeCuoi(PT);
									cout<<"Danh sach sau khi xoa phan tu cuoi cung: \n";
									xuatdspt(PT);
									break;
								}
								
								case 8:
									luuf(PT, filename2);
								 break;
							
								case 9: 
									DocFilePT(PT, filename2);
									break;
							 	case 0 :
							 	break;								
						}
					}
					while (choose!=0);
								break;
							}
			case 0: exit(0);
		}
	}while(luachon!=0);
}

