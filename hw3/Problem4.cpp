#include <iostream>
#include <cstdlib> 
#include <cstring>
#include <fstream>
#include <vector>
using std::ifstream;
using std::ofstream;
using namespace std;


void Symmetric(std::vector<char>&myvector,int relation_number){

	int i,j,r1_left=0,r2_left=0;
	int count=0;
	
	for(i=0;i<myvector.size()/2;i++){
		for(j=0;j<myvector.size()/2;j++){
			if(myvector[r1_left]==myvector[r2_left+1] && myvector[r1_left+1]==myvector[r2_left] && r1_left!=r2_left){

				myvector.erase(myvector.begin()+r2_left);			//I delete the symmetric expressions I find from the vector.
				myvector.erase(myvector.begin()+r2_left);

			}
			r2_left=r2_left+2;					//I scroll through the statements and find symmetrical expressions.

		}
		count=0;
		r2_left=0;
		r1_left=r1_left+2;
	}
}	

void Transitive(std::vector<char>&myvector,int relation_number,int select){

	int i,j,l;
	int r2_left=0;
	int count=0;
	int r1_left=0;
	int r3_left=0;


	for(i=0;i<myvector.size()/2;i++){			//I have 3 for loop because I am interested in 3 relations in this function.
		for(j=0;j<myvector.size()/2;j++){
			if(myvector[r1_left+1]==myvector[r2_left] && r1_left!=r2_left){	//I take a relation and compare it with others ' indices.
				count=0;
				for(l=0;l<myvector.size()/2;l++){
					if(myvector[r1_left]==myvector[r3_left] && myvector[r2_left+1]==myvector[r3_left+1] && r1_left!=r3_left  ){//this condition provides transitive.

						count++;				//I find the third relation that provides transistivity with the method of finding transistive.
						if(select==1){
							myvector.erase(myvector.begin()+r3_left);		//I delete the relation I found from the POSET statement.
							myvector.erase(myvector.begin()+r3_left);
						}
					}
					
					r3_left=r3_left+2;
				}
				if(count==0  && myvector[r1_left+1]!=myvector[r2_left+1] && myvector[r2_left]!=myvector[r3_left] && select==0){
						myvector.push_back(myvector[r1_left]);		
						myvector.push_back(myvector[r2_left+1]);	//When I prepare POSET, I add transistive if it is missing.
						break;
				}
			}
		
			r3_left=0;
			r2_left=r2_left+2;
		}
		
		r2_left=0;
		r1_left=r1_left+2;
	}
	
}

void reflexive(std::vector<char>&myvector,int relation_number,int size,string line,int select){
	int count=0;
	int i,j=0;
	int k=0;
	char a;
	int sayac=0;
	char b;								// line string variable is a variable that holds elements in it.
	int flag=0; 


	if(select==0){
		for(i=0;i<size;i++){
			flag=0;
			j=0;
			for(int c=0;c<relation_number;c++){
				if(myvector[j]==line[k] && myvector[j+1]==line[k]){	//checking reflexive.
					flag++;
					break;				
				}
				j=j+2;					//I use this field while preparing POSET.
			}

			if(flag==0){
				myvector.push_back(line[k]);	//If there is no relation  I'm looking for, I'm adding it.
				myvector.push_back(line[k]);
				
			}
			k=k+2;
			
		}
	}
	else if(select==1){
		k=0;
		for(i=0;i<size;i++){
			flag=0;
			j=0;
			for(int c=0;c<myvector.size()/2;c++){
				if(myvector[j]==line[k] && myvector[j+1]==line[k]){	//checking reflexive.
					myvector.erase(myvector.begin()+j);			//I delete the reflexives I find.
					myvector.erase(myvector.begin()+j);
					break;
				}
				j=j+2;
			}
			k=k+2;
		
		}

	}
		
}


int main(){
	std::vector<char>myvector;
	char array[100];
	string okan;
	int relation_number;
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
		myvector.clear();
		relation_number=0;
		inStream>>relation_number;//relation number
		if(relation_number!=0){
			getline(inStream,line);
			getline(inStream,line);	//Set elements
			size=(line.length()+1)/2;	//the number of elements
			for(i=0;i<relation_number;i++){
				getline(inStream,okan);		//I m printing relation every time.
				myvector.push_back(okan[0]);
				myvector.push_back(okan[2]);
				j=j+2;
			}
			j=0;
			reflexive(myvector,relation_number,size,line,0);		//I am preparing the POSET statement.
			Symmetric(myvector,relation_number);
			Transitive(myvector,relation_number,0);
			cout<<"n"<<endl<<"POSET : ";
			outStream2<<"n"<<endl<<"POSET : ";
			for(i=0;i<myvector.size();i=i+2){
				outStream2<<"("<<myvector[i]<<","<<myvector[i+1]<<") ,";
				cout<<"("<<myvector[i]<<","<<myvector[i+1]<<") ,";
			}
			cout<<endl;
			outStream2<<endl;
			reflexive(myvector,relation_number,size,line,1);			//I delete the transitive and reflexivities in the expression.
			Transitive(myvector,relation_number,1);
			
			for(i=0;i<myvector.size();i=i+2){
				cout<<myvector[i]<<","<<myvector[i+1]<<endl;
			    outStream2<<myvector[i]<<","<<myvector[i+1]<<endl;
			}
			outStream2<<endl<<endl;

		}
		
	}
	outStream.close( );
	outStream2.close( );
	inStream.close( );
	
}