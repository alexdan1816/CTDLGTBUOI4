#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct StuList
{
    long mssv;
    char hoten[100];
    float CPA;
    struct StuList *next;
} StuList;

struct StuList *ListInit() // tạo danh sách rỗng
{
    return NULL;
}

bool isEmpty(struct StuList *H) // Kiểm tra danh sách rỗng
{
    return (H == NULL);
}

struct StuList *createStudentNode() // tạo một node lưu trữ các thông tin của sinh viên
{
    struct StuList *StuNew = (struct StuList *)malloc(sizeof(struct StuList));
    printf("Nhap thong tin sinh vien\n");
    printf("MSSV: ");
    scanf("%ld", &StuNew->mssv);
    getchar();
    printf("Ho va Ten: ");
    fgets(StuNew->hoten, sizeof(StuNew->hoten), stdin);
    fflush(stdin);
    printf("GPA: ");
    scanf("%f", &StuNew->CPA);
    getchar();
    StuNew->next = NULL;
    return StuNew;
}

struct StuList *StuAddBegin(struct StuList *H) // bổ sung sinh viên vào đầu danh sách
{
    struct StuList *StuNewNode = (struct StuList *)malloc(sizeof(struct StuList));
    StuNewNode = createStudentNode();
    if (isEmpty(H))
    {
        return StuNewNode;
    }
    StuNewNode->next = H;
    return StuNewNode;
}

void StuFind(struct StuList *H, long mssvf) // Tìm kiếm sinh viên khi biết mssv
{

    if (isEmpty(H))
    {
        printf("Danh sach rong\n");
        return;
    }
    struct StuList *find = H;
    while (find != NULL && find->mssv != mssvf)
    {
        find = find->next;
    }
    if (find == NULL)
    {
        printf("Khong co sinh vien trung khop\n");
        return;
    }
    printf("Thong tin sinh vien: \n");
    printf("*MSSV: %ld\n", find->mssv);
    printf("*Ho va Ten: %s\n", find->hoten);
    printf("*CPA: %f\n", find->CPA);
    return;
}

struct StuList *StuAddAfterStu(struct StuList *H, long mssvf) // Bổ sung sinh viên vào sau sinh viên có mssv
{
    struct StuList *StuNewNode = (struct StuList *)malloc(sizeof(struct StuList));
    StuNewNode = createStudentNode();
    if (isEmpty(H))
    {
        return StuNewNode;
    }
    struct StuList *find = H;
    while (find != NULL && find->mssv != mssvf)
    {
        find = find->next;
    }
    if (find == NULL)
    {
        printf("khong tim thay sinh vien trung khop");
        return H;
    }
    StuNewNode->next = find->next;
    find->next = StuNewNode;
    return H;
}

struct StuList *StuAddBeforeStu(struct StuList *H, long mssvf) // Bổ sung sinh viên vào trước sinh viên có mssv
{
    struct StuList *StuNewNode = (struct StuList *)malloc(sizeof(struct StuList));
    StuNewNode = createStudentNode();
    struct StuList *find = H;
    if (isEmpty(H))
    {
        printf("Khong tim thay sinh vien trung khop\n");
        return H;
    }
    while (find != NULL && find->mssv != mssvf)
    {
        find = find->next;
    }
    if (find == NULL)
    {
        printf("Khong tim thay sinh vien trung khop\n");
        return H;
    }
    else if (find == H)
    {
        StuNewNode->next = H;
        return StuNewNode;
    }

    struct StuList *temp = (struct StuList *)malloc(sizeof(struct StuList));
    temp->CPA = find->CPA;
    temp->mssv = find->mssv;
    strcpy(temp->hoten, find->hoten);
    temp->next = NULL;

    find->CPA = StuNewNode->CPA;
    find->mssv = StuNewNode->mssv;
    strcpy(temp->hoten, find->hoten);
    StuNewNode->next = find->next;
    find->next = StuNewNode;

    StuNewNode->CPA = temp->CPA;
    StuNewNode->mssv = temp->mssv;
    strcpy(StuNewNode->hoten, temp->hoten);
    free(temp);

    return H;
}

struct StuList *StuFirstDelete(struct StuList *H) // xóa sinh viên ở đầu danh sách
{
    struct StuList *toDelete = H;
    if (isEmpty(H))
    {
        printf("Danh sach rong");
        return H;
    }
    if (H->next == NULL)
    {
        free(H);
        return NULL;
    }
    H = H->next;
    free(toDelete);
    return H;
}

struct StuList *StuMSSVdelete(struct StuList *H, long mssvf) // xóa sinh viên biết mã số sinh viên
{
    if (isEmpty(H))
    {
        printf("Danh sach rong");
        return NULL;
    }
    struct StuList *find = H;
    while (find != NULL && find->mssv != mssvf)
    {
        find = find->next;
    }
    if (find == NULL)
    {
        printf("Khong co sinh vien trung khop\n");
        return H;
    }

    struct StuList *temp = H;
    while (temp->next != find)
    {
        temp = temp->next;
    }

    temp->next = find->next;
    free(find);
    return H;
}

struct StuList *StuPDelete(struct StuList *H, struct StuList *P) // Xóa sinh viên hiện tại được trỏ bởi con trỏ P
{
    if (isEmpty(H))
    {
        printf("Danh sach trong \n");
        return NULL;
    }
    if (H == P)
        ;
    {
        struct StuList *toDelete = H;
        H = H->next;
        free(toDelete);
        return H;
    }

    struct StuList *prev = H;
    while (prev != NULL && prev->next != P)
    {
        prev = prev->next;
    }
    if (prev == NULL)
    {
        printf("khong tim thay sinh vien trung khop\n");
        return H;
    }
    prev->next = P->next;
    free(P);
    return H;
}

void BestStuSearch(struct StuList *H)
{
    if (isEmpty(H))
    {
        printf("Danh sach trong \n");
        return;
    }
    struct StuList *current = H;
    float top = current->CPA;
    while (current != NULL)
    {
        if (top <= current->CPA)
            ;
        top = current->CPA;
        H = current->next;
    }

    struct StuList *TOP = H;

    while (TOP != NULL)
    {
        if (TOP->CPA == top)
        {
            StuFind(H, TOP->mssv);
        }
        TOP = TOP->next;
    }
}
void display(struct StuList *H)
{
    int i = 1;
    if (isEmpty(H))
    {
        printf("Danh sach trong");
        return;
    }
    while (H != NULL)
    {
        printf("thong tin sinh vien thu %d: \n", i);
        printf("Thong tin sinh vien: \n");
        printf("*MSSV: %ld\n", H->mssv);
        printf("*Ho va Ten: %s\n", H->hoten);
        printf("*CPA: %f\n", H->CPA);
        H = H->next;
    }
    return;
}

int main()
{
    struct StuList *head = ListInit(); // Khởi tạo danh sách rỗng
    struct StuList *P = NULL;          // Con trỏ tạm để test các phép toán

    // Thêm sinh viên vào đầu danh sách
    printf("\nThem sinh vien vao dau danh sach:\n");
    head = StuAddBegin(head);

    // Thêm sinh viên tiếp theo vào đầu danh sách
    printf("\nThem sinh vien thu hai:\n");
    head = StuAddBegin(head);

    // Hiển thị danh sách sinh viên
    printf("\nHien thi danh sach sinh vien:\n");
    display(head);

    // Tìm kiếm sinh viên theo MSSV
    printf("\ntim sinh vien voi mssv dau tien:\n");
    long mssv1 = head->mssv;
    StuFind(head, mssv1);

    // Thêm sinh viên sau sinh viên có MSSV đã cho
    printf("\nthem sinh vien vao sau sinh vien dau tien:\n");
    head = StuAddAfterStu(head, mssv1);

    // Hiển thị danh sách sinh viên sau khi thêm
    printf("\nHien thi danh sach sau khi them sinh vien:\n");
    display(head);

    // Xóa sinh viên đầu tiên trong danh sách
    printf("\nXoa sinh vien dau tien:\n");
    head = StuFirstDelete(head);

    // Hiển thị danh sách sau khi xóa
    printf("\nHien thi danh sach sau khi xoa sinh vien:\n");
    display(head);

    // Xóa sinh viên dựa trên con trỏ P (giả sử chúng ta xóa sinh viên hiện tại là đầu danh sách)
    P = head;
    printf("\nxoa sinh vien duoc chi boi con tro p\n");
    head = StuPDelete(head, P);

    // Hiển thị danh sách sau khi xóa sinh viên được trỏ bởi P
    printf("\nHien thi danh sach sau khi xoa:\n");
    display(head);

    return 0;
}
