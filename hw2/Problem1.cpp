#include <iostream>
#include <cstdlib> //for exit
#include <cstring>
#include <fstream>
using std::ifstream;
using std::ofstream;
using namespace std;
void isAntiisSymmetric(char array[100],int temp,int size){

	int k=0,m=0;
	int count=0;
	bool found = false;
	char a,b;

	ofstream outStream;
	outStream.open("output.txt",ios::app);

	for(int i=0;i<temp;i++){
		for(int j=0;j<temp;j++){
			if(array[k]==array[m+1] && array[k+1]==array[m] && k!=m){
				count++;							//I'm checking the symmetry in the condition here
				a=array[m];		//if I find one isSymmetrical,I go into a condition that increases my counter and does not provide isAntiisSymmetric.
				b=array[m+1];
			}
			m=m+2;
			if(count!=0){
				outStream<<"isAntiisSymmetric: No, ("<<a <<","<<b<<") is found ("<< b <<","<<a <<") is found."<<endl;
				cout<<"isAntiisSymmetric: No, ("<<a <<","<<b<<") and ("<< b <<","<<a <<") are found.";
				found =true;
				break;

			}		//if I have never found isSymmetric,that is,if I have not increased my counter, there is isAntiisSymmetric.
			if(m==temp*2 && count==0 && array[k]!=array[k+1]){
				outStream<<"isAntiisSymmetric: Yes, ("<<array[k] <<","<<array[k+1]<<") is found whereas ("<< array[k+1] <<","<<array[k] <<") is not found."<<endl;
				cout<<"isAntiisSymmetric: Yes, ("<<array[k] <<","<<array[k+1]<<") is found whereas ("<< array[k+1] <<","<<array[k] <<") is not found.";
				found=true;
				break;
			}

		}
		if(found)
			break;
		count=0;
		m=0;
		k=k+2;				//the m and k Values are my control values when circulating in the loop.

	}
	if(!found){
		if(a=='\0'){//if all values are all isReflexive, I direct to this condition.
			outStream<<"isAntiisSymmetric: Yes, For example:"<<"("<<array[0]<<","<<array[0]<<")"<<" does not disrupt isAntiisSymmetric."<<endl;
			cout<<"isAntiisSymmetric: Yes, For example:"<<"("<<array[0]<<","<<array[0]<<")"<<" does not disrupt isAntiisSymmetric.";
		}
		else{
			outStream<<"isAntiisSymmetric: No,Not isAntiisSymmetric. For example:"<<"Whereas "<<"("<<a<<","<<b<<")"<<" is found"<<" and "<<"("<<b<<","<<a<<")"<<" should not be found."<<endl;
			cout<<"isAntiisSymmetric: No,Not isAntiisSymmetric. For example:"<<"Whereas "<<"("<<a<<","<<b<<")"<<" is found"<<" and "<<"("<<b<<","<<a<<")"<<" should not be found.";
		}
	}
	outStream.close( );

}	

void isSymmetric(char array[100],int temp,int size){

	int k=0,m=0;
	int count=0;
	bool found=false;
	char exValues1,exValues2;

	ofstream outStream;
	outStream.open("output.txt",ios::app);

	for(int i=0;i<temp;i++){		
		for(int j=0;j<temp;j++){
			if(array[k]==array[m+1] && array[k+1]==array[m] && k!=m){
				count++;			//I'm checking for isSymmetric in the condition here.
				exValues1=array[m];
				exValues2=array[m+1]; //I'm taking two values to give an example.
			}
			m=m+2;

			//if I can't find the isSymmetric of the value I'm checking and I'm at the end of the cycle, I'm going to this condition .
			//is not isSymmetric
			if(m==temp*2 && count==0 && array[k]!=array[k+1]){//
				outStream<<"isSymmetric: No, "<<array[k] <<","<<array[k+1]<<" is found whereas "<< array[k+1] <<","<<array[k] <<" is not found."<<endl;
				cout<<"isSymmetric: No, "<<array[k] <<","<<array[k+1]<<" is found whereas "<< array[k+1] <<","<<array[k] <<" is not found.";
				found=true;
				break;
			}
		}
		if(found)
			break;
		count=0;
		m=0;
		k=k+2;

	}
	if(!found){		////if all values are all isReflexive, I direct to this condition.
		if(exValues1=='\0'){
			outStream<<"isSymmetric: Yes,isSymmetric For example:"<<"("<<array[0]<<","<<array[0]<<") does not disrupt isSymmetric."<<endl;
			cout<<"isSymmetric: Yes,isSymmetric For example:("<<array[0]<<","<<array[0]<<") does not disrupt isSymmetric.";
		}
		else{
			outStream<<"isSymmetric: Yes,isSymmetric For example:"<<"("<<exValues1<<","<<exValues2<<")"<<" and "<<"("<<exValues2<<","<<exValues1<<")"<<endl;
			cout<<"isSymmetric: Yes,isSymmetric For example:"<<exValues1<<","<<exValues2<<" and "<<exValues2<<","<<exValues1;
		}
	}
	outStream.close( );

}	

void isSymmetric(char array[100],int relation_number,int size){

	int i,j,l;
	int r2_left=0;
	int count=0;
	int r1_left=0;
	int flag=0;
	int r3_left=0;
	int count2=0;
	int temp2,temp3;
	char b,e,f,g,t,y;
	int special=0;

	ofstream outStream;
	outStream.open("output.txt",ios::app);

	for(i=0;i<relation_number;i++){			//I have 3 for loop because I am interested in 3 relations in this function.
		for(j=0;j<relation_number;j++){
			if(array[r1_left+1]==array[r2_left] && r1_left!=r2_left){	//I take a relation and compare it with others ' indices.
				special++;
				count=0;
				for(l=0;l<relation_number;l++){
					if(array[r1_left]==array[r3_left] && array[r2_left+1]==array[r3_left+1] && r1_left!=r3_left  ){//this condition provides isSymmetric.
					
						if(array[r2_left]!=array[r3_left]){
							t=array[r1_left];
							b=array[r1_left+1];
							y=array[r2_left];				
							e=array[r2_left+1];				////I'm recording a transative sample I found here.
							f=array[r3_left];
							g=array[r3_left+1];		
						}
					
						count++;						
					}
										
					r3_left=r3_left+2;
				}
				if(count==0  && array[r1_left+1]!=array[r2_left+1] && array[r2_left]!=array[r3_left]){
						cout<<"NO TRANSİSTİVE "<<array[r1_left]<<","<<array[r1_left+1]<<" and "
						<<array[r2_left]<<","<<array[r2_left+1]<<" found but "<<array[r1_left]<<","<<array[r2_left+1]<<" not found"<<endl;
						outStream<<"NO TRANSİSTİVE "<<array[r1_left]<<","<<array[r1_left+1]<<" and "
						<<array[r2_left]<<","<<array[r2_left+1]<<" found but "<<array[r1_left]<<","<<array[r2_left+1]<<" not found"<<endl;
						flag++;
						break;
				}
				
				
			}
		
			r3_left=0;
			r2_left=r2_left+2;
		}
		
		
		r2_left=0;
		r1_left=r1_left+2;

	}
	if(flag==0 && special==0){
		cout<<"Transistive : Yes ("<<array[0]<<","<<array[1]<<") is found since ("						//I come to this area if the relations are all isReflexive.
		<<array[0]<<","<<array[1]<<") and ("<<array[0]<<","<<array[1]<<")"<<endl;
		outStream<<"Transistive : Yes ("<<array[r1_left]<<","<<array[r1_left+1]<<") is found since ("
		<<array[r2_left]<<","<<array[r2_left+1]<<") and ("<<array[r3_left]<<","<<array[r3_left+1]<<")"<<endl;

	}
	else if(flag==0){
		cout<<"Transistive : Yes ("<<f<<","<<g<<") is found since ("
		<<t<<","<<b<<") and ("<<y<<","<<e<<")"<<endl;
		outStream<<"Transistive : Yes ("<<f<<","<<g<<") is found since ("
		<<t<<","<<b<<") and ("<<y<<","<<e<<")"<<endl;

	}
	
	
	outStream.close( );


}
void isReflexive(char array[100],int temp,int size,string line){
	int count=0;
	int j=0;
	int k=0;
	char a;
	int sayac=0;
	char b;								// line string variable is a variable that holds elements in it.

	ofstream outStream;
	outStream.open("output.txt",ios::app);
	for(int i=0;i<temp;i++){
		if(array[j]==array[j+1]){	//checking isReflexive.
			if(array[j]!=line[k]){		//this condition checks to see if the isReflexive is broken.
				a=line[k];		//I'm saving the value that breaks isReflexive to show an example
				sayac++;		//to exit from the loop
				break;
			}
			b=array[j];		//to illustrate an example of the situation that allows isReflexive.
			count++;			//every time I find a isReflexive, I increase my counter
			k=k+2;

		}
		j=j+2;
		if(sayac!=0)
			break;
		if(i==temp-1 && count!=size)
			a=line[k];
	}

		//if my counter is equal to the number of elements, it is isReflexive.

	if(count==size){
		outStream<<"isReflexive: Yes, all elements are present.For example: "<<"("<<b<<","<<b<<")"<<endl;
		cout<<"isReflexive: Yes, all elements are present.For example: "<<"("<<b<<","<<b<<")";
	}
	else{
		outStream<<"isReflexive: ("<<a<<","<<a<<")"<< "not found"<<endl;
		cout<<"isReflexive: ("<<a<<","<<a<<")"<< "not found";
	}
	outStream.close( );
	
	

}


int main(){
	char array[100];
	string okan;
	int temp;
	int i;
	int j=0;
	int size;
	string line;
	ifstream inStream;
	ofstream outStream,outStream2;

	outStream.open("output.txt");
	outStream2.open("output.txt",ios::app);
	inStream.open("input.txt");
	
	while(!inStream.eof()){
		temp=0;
		inStream>>temp;//relation number
		if(temp!=0){
			getline(inStream,line);
			getline(inStream,line);	//Set elements
			size=(line.length()+1)/2;	//the number of elements
			outStream2<<"n"<<endl;
			for(i=0;i<temp;i++){
				getline(inStream,okan);		//I m printing relation every time.
				outStream2<<"("<<okan<<")";
				array[j]=okan[0];		//I m putting elemnts of set into array.  
				array[j+1]=okan[2];
				j=j+2;
			}
			j=0;
			outStream2<<endl;
			isReflexive(array,temp,size,line);			//I'm printing the results accordingly.
			cout<<endl;
			isSymmetric(array,temp,size);
			cout<<endl;
			isAntiisSymmetric(array,temp,size);
			cout<<endl;
			isSymmetric(array,temp,size);
			cout<<endl;
		}
		
	}
	outStream.close( );
	outStream2.close( );
	inStream.close( );
	
}