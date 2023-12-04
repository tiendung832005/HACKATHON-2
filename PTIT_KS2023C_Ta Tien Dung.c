#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct Todo {
	int id;
	char startDate[50];
	char endDate[50];
	char content[100];
	bool status;
};
void displayTodo(struct Todo arr[], int size){
	for(int i=0;i<size;i++){
					printf("ID: %d\n", arr[i].id);
					printf("Ngay bat dau: %s\n", arr[i].startDate);
					printf("Ngay ket thuc: %s\n", arr[i].endDate);
					printf("Noi dung ke hoach: %s\n", arr[i].content);
					printf("Trang thai: %d\n", arr[i].status);
					printf("-------------------------------\n");
				}
}
int searchTodo(struct Todo arr[], int size, char answer[50]){
	int index;
	int updateIndex = -1;
				for(int i=0; i<size;i++){
					if(strcmp(arr[i].content, answer) == 0){
						int index = i;
						
					}
					
				}
				return index;
	
}
int main(){
	struct Todo todo1 = {1, "1/12/2023", "15/12/2023", "Chay bo", false
	};
	struct Todo todo2 = {2, "20/10/2023", "20/11/2023", "Giam can", true
	};
	struct Todo todoList [50] = {todo1, todo2,
	};
	int currentSize = 2;
	do{
		printf("\n***********MENU***********\n");
		printf("1. In ra toan bo danh sach Todo\n");
		printf("2. Them moi todo vao vi tri cuoi cung\n");
		printf("3. Chinh sua todo\n");
		printf("4. Xoa 1 todo\n");
		printf("5. Sap xep va in ra danh sach todoList da duoc sap xep tang dan\n");
		printf("6. Tim kiem va in ra thong tin cua todo theo content\n");
		printf("7. Tim kiem va in ra toan bo thong tin cua cac todo theo status\n");
		printf("8. Thoat \n");
		int choice;
		printf("Lua chon cua ban la: ");
		scanf("%d", &choice);
		char answer[100];
		switch (choice){
			case 1:
				displayTodo(todoList, currentSize);
			break;
			case 2:
				printf("Them moi mot todo vao todoList\n");
				struct Todo newTodo;
				printf("Nhap vao ID: ");
				scanf("%d", &newTodo.id);
				
				printf("Nhap vao thoi gian bat dau: ");
				scanf("\n");
				gets(newTodo.startDate);
				
				printf("Nhap vao thoi gian ket thuc: ");
				gets(newTodo.endDate);
				
				printf("Nhap vao noi dung ke hoach: ");
				gets(newTodo.content);
				
				printf("Nhap vao trang thai: ");
				scanf("%d", &newTodo.status);
				
				todoList[currentSize] = newTodo;
				currentSize++;
				
				displayTodo(todoList, currentSize);
			break;
			case 3:
				printf("Nhap vao todo ban muon chinh sua: \n");
				scanf("\n");
				gets(answer);
				int updateIndex = searchTodo(todoList, currentSize, answer);
				
				
				if(updateIndex != -1){
				printf("Nhap vao thoi gian bat dau moi cap nhat: ");
				scanf("\n");
				gets(todoList[updateIndex].startDate);
				
				printf("Nhap vao thoi gian ket thuc moi cap nhat: ");
				gets(todoList[updateIndex].endDate);
				
				printf("Nhap vao noi dung ke hoach moi cap nhat: ");
				gets(todoList[updateIndex].content);
				
				printf("Nhap vao trang thai moi cap nhat: ");
				scanf("%d", &todoList[updateIndex].status);
				
				displayTodo(todoList, currentSize);
					
				}
				else{
					printf("Khong tim thay!!");
				}
				
				break;
			case 4:
				printf("Nhap vao todo ban muon xoa: \n");
				scanf("\n");
				gets(answer);
				int deleteIndex = searchTodo(todoList, currentSize, answer);
				
				if(deleteIndex != -1){
					for(int i= deleteIndex; i< currentSize; i++){
						todoList[i] = todoList[i+1];
					}
					currentSize--;
					displayTodo(todoList, currentSize);
					
				}
				break;
			case 6:
				
			case 8:
				printf("Ket thuc chuong trinh\n");
				exit(0);
				default:
					printf("Moi ban chon tu 1 den 8\n");
							
		}
		
		
	}
	while(1==1);
}
