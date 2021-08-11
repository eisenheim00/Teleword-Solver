#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;

bool istep=false;
int dir,row_pos, col_pos ;
int hori_f= 0, ver_d = 0 , hori_b=0 , ver_u=0, dia_f =0, dia_b = 0;
int heaviest_r=0 ,heaviest_c=0,t_heaviest_r=0,t_heaviest_c=0; 
COORD coord={0,0};
void colorxy(int rowpos, int colpos,int direction, char word[], int counter[][16])
{
int colour = 0;
int x = coord.X=colpos*2;
int y = coord.Y=rowpos;
HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
int wordlength = strlen(word);
if (direction==1)
{ 
 for (int x=coord.X,leter=0 ; leter<wordlength ;  x += 2 , ++leter)
 {
   coord.X=x;  
   SetConsoleCursorPosition(hOuput,coord);

    counter[y][x]++;
    if (counter[y][x] == 1)
    {
        colour = 14;
    }
    else if (counter[y][x] == 2)
    {
        colour = 13;
    }
    else{
        colour = 12;
    }
        
   SetConsoleTextAttribute(hOuput,colour);
   cout << word[leter];
 }
}
else if (direction==5)
{ 
 for (int x=coord.X,leter=0 ; leter < wordlength ;  x -= 2 , ++leter)
 {
   coord.X=x;  
   SetConsoleCursorPosition(hOuput,coord);
   counter[y][x]++;
    if (counter[y][x] == 1)
    {
        colour = 14;
    }
    else if (counter[y][x] == 2)
    {
        colour = 13;
    }
    else{
        colour = 12;
    }

   SetConsoleTextAttribute(hOuput,colour);
   cout << word[leter];
 }
}
else if (direction==3)
{ 
 for (int y=coord.Y,leter=0 ; leter<wordlength ;  y++ , ++leter)
 {
   coord.Y=y;  
   SetConsoleCursorPosition(hOuput,coord);
   counter[y][x]++;
    if (counter[y][x] == 1)
    {
        colour = 14;
    }
    else if (counter[y][x] == 2)
    {
        colour = 13;
    }
    else{
        colour = 12;
    }

   SetConsoleTextAttribute(hOuput,colour);
   cout << word[leter];
 }
}
else if (direction==7)
{ 
 for (int y=coord.Y,leter=0 ; leter < wordlength ;  y-- , ++leter)
 {
   coord.Y=y;  
   SetConsoleCursorPosition(hOuput,coord);
   counter[y][x]++;
    if (counter[y][x] == 1)
    {
        colour = 14;
    }
    else if (counter[y][x] == 2)
    {
        colour = 13;
    }
    else{
        colour = 12;
    }

   SetConsoleTextAttribute(hOuput,colour);
   cout << word[leter];
 }
}
else if (direction==8)
{ 
 for (int x=coord.X,y=coord.Y,leter=0 ; leter<wordlength ;x += 2,  y-- , ++leter)
 {
   coord.Y=y;
   coord.X=x; 
   SetConsoleCursorPosition(hOuput,coord);
   counter[y][x]++;
    if (counter[y][x] == 1)
    {
        colour = 14;
    }
    else if (counter[y][x] == 2)
    {
        colour = 13;
    }
    else{
        colour = 12;
    }

   SetConsoleTextAttribute(hOuput,colour);
   cout << word[leter];
 }
}
else if (direction==2)
{ 
 for (int x=coord.X,y=coord.Y,leter=0 ; leter<wordlength ;x += 2,  ++y , ++leter)
 {
   coord.Y=y;
   coord.X=x; 
   SetConsoleCursorPosition(hOuput,coord);
   counter[y][x]++;
    if (counter[y][x] == 1)
    {
        colour = 14;
    }
    else if (counter[y][x] == 2)
    {
        colour = 13;
    }
    else{
        colour = 12;
    }

   SetConsoleTextAttribute(hOuput,colour);
   cout << word[leter];
 }
}
else if (direction==4)
{ 
 for (int x=coord.X,y=coord.Y,leter=0 ; leter<wordlength ;x -= 2,  ++y , ++leter)
 {
   coord.Y=y;
   coord.X=x; 
   SetConsoleCursorPosition(hOuput,coord);
   counter[y][x]++;
    if (counter[y][x] == 1)
    {
        colour = 14;
    }
    else if (counter[y][x] == 2)
    {
        colour = 13;
    }
    else{
        colour = 12;
    }

   SetConsoleTextAttribute(hOuput,colour);
   cout << word[leter];
 }
}
else if (direction==6)
{ 
 for (int x=coord.X,y=coord.Y,leter=0 ; leter<wordlength ;x -= 2,  --y , ++leter)
 {
   coord.Y=y;
   coord.X=x; 
   SetConsoleCursorPosition(hOuput,coord);
   counter[y][x]++;
    if (counter[y][x] == 1)
    {
        colour = 14;
    }
    else if (counter[y][x] == 2)
    {
        colour = 13;
    }
    else{
        colour = 12;
    }

   SetConsoleTextAttribute(hOuput,colour);
   cout << word[leter];
 }
}
}
void find_hori_forward( char grid[][16],  char word[],int & hori_f,int & t_heaviest_c)
{
	bool found = false;
	int r = 0, c = 0; // r is row, c is column
	int wordno = 0;
    int length = strlen(word);
	for (r = 0; r < 15 ; ++r)
	{
		for (c = 0; c <15; ++c)
		{
			if (grid[r][c] == word[wordno])
			{
				int l = 0;
				for (int tempcol = c; l < length ; ++l)
				{
					if (grid[r][tempcol] == word[wordno])
					{
						found = true;
						++tempcol;
						++wordno;
                        ++t_heaviest_c;
					}
					else
					{
						found = false;
						wordno = 0;
                        t_heaviest_c=0;
                        break;
					}
				}
                if(found == true)
                {
                    row_pos=r;
                    col_pos=c;
                    dir=1;
                    ++hori_f;
                }
			}
		}
	}
}
void find_hori_backward( char grid[][16],  char word[],int & hori_b,int & t_heaviest_c)
{
	bool found = false;
	int r = 0, c = 0; // r is row, c is column
	int wordno = 0;
    int length = strlen(word);
	for (r = 0; r < 15 ; ++r)
	{
		for (c = 0; c <15; ++c)
		{
			if (grid[r][c] == word[wordno])
			{
				int l = 0;
				for (int tempcol = c; l < length ; ++l)
				{
					if (grid[r][tempcol] == word[wordno])
					{
						found = true;
						--tempcol;
						++wordno;
                        ++t_heaviest_c;
					}
					else
					{
						found = false;
						wordno = 0;
                        t_heaviest_c=0;
                        break;
					}
				}
                if(found == true)
                {
                    row_pos=r;
                    col_pos=c;
                    dir=5;
                    ++hori_b;
                }
			}
		}
	}
}
void find_vertical_down( char grid[][16],  char word[],int & ver_d,int & t_heaviest_r)
{
	bool found = false;
	int r = 0, c = 0; // r is row, c is column
	int wordno = 0;
    int length = strlen(word);
	for (r = 0; r < 15 ; ++r)
	{
		for (c = 0; c <15; ++c)
		{
			if (grid[r][c] == word[wordno])
			{
				int l = 0;
				for (int temprow = r; l < length ; ++l)
				{
					if (grid[temprow][c] == word[wordno])
					{
						found = true;
						++temprow;
						++wordno;
                        ++t_heaviest_r;
					}
					else
					{
						found = false;
						wordno = 0;
                        t_heaviest_r=0;
                        break;
					}
				}
                if(found == true)
                {
                    row_pos=r;
                    col_pos=c;
                    dir=3;
                    ++ver_d;
                }
			}
		}
	}
}
void find_vertical_up( char grid[][16],  char word[],int & ver_u,int & t_heaviest_r)
{
	bool found = false;
	int r = 0, c = 0; // r is row, c is column
	int wordno = 0;
    int length = strlen(word);
	for (r = 0; r < 15 ; ++r)
	{
		for (c = 0; c <15; ++c)
		{
			if (grid[r][c] == word[wordno])
			{
				int l = 0;
				for (int temprow = r; l < length ; ++l)
				{
					if (grid[temprow][c] == word[wordno])
					{
						found = true;
						--temprow;
						++wordno;
                        ++t_heaviest_r;
					}
					else
					{
						found = false;
						wordno = 0;
                        t_heaviest_r=0;
                        break;
					}
				}
                if(found == true)
                {
                    row_pos=r;
                    col_pos=c;
                    dir=7;
                    ++ver_u;
                }
			}
		}
	}
}
void find_diag_upright( char grid[][16],  char word[],int & dia_f,int & t_heaviest_r,int & t_heaviest_c)
{
	bool found = false;
	int r = 0, c = 0; // r is row, c is column
	int wordno = 0;
    int length = strlen(word);
	for (r = 0; r < 15 ; ++r)
	{
		for (c = 0; c <15; ++c)
		{
			if (grid[r][c] == word[wordno])
			{
				int l = 0;
				for (int tempcol = c , temprow = r; l < length ; ++l)
				{
					if (grid[temprow][tempcol] == word[wordno])
					{
						found = true;
						++tempcol;
                        --temprow;
						++wordno;
                        ++t_heaviest_r;
                        ++t_heaviest_c;
					}
					else
					{
						found = false;
						wordno = 0;
                        t_heaviest_r=0;
                        t_heaviest_c=0;
                        break;
					}
				}
                if(found == true)
                {
                    row_pos=r;
                    col_pos=c;
                    dir=8;
                    ++dia_f;
                }
			}
		}
	}
}
void find_diag_downright( char grid[][16],  char word[],int & dia_f,int & t_heaviest_r,int & t_heaviest_c)
{
	bool found = false;
	int r = 0, c = 0; // r is row, c is column
	int wordno = 0;
    int length = strlen(word);
	for (r = 0; r < 15 ; ++r)
	{
		for (c = 0; c <15; ++c)
		{
			if (grid[r][c] == word[wordno])
			{
				int l = 0;
				for (int tempcol = c , temprow = r; l < length ; ++l)
				{
					if (grid[temprow][tempcol] == word[wordno])
					{
						found = true;
						++tempcol;
                        ++temprow;
						++wordno;
                        ++t_heaviest_r;
                        ++t_heaviest_c;
					}
					else
					{
						found = false;
						wordno = 0;
                        t_heaviest_r=0;
                        t_heaviest_c=0;
                        break;
					}
				}
                if(found == true)
                {
                    row_pos=r;
                    col_pos=c;
                    dir=2;
                    ++dia_f;
                }
			}
		}
	}
}
void find_diag_downleft( char grid[][16],  char word[],int & dia_b,int & t_heaviest_r,int & t_heaviest_c)
{
	bool found = false;
	int r = 0, c = 0; // r is row, c is column
	int wordno = 0;
    int length = strlen(word);
	for (r = 0; r < 15 ; ++r)
	{
		for (c = 0; c <15; ++c)
		{
			if (grid[r][c] == word[wordno])
			{
				int l = 0;
				for (int tempcol = c , temprow = r; l < length ; ++l)
				{
					if (grid[temprow][tempcol] == word[wordno])
					{
						found = true;
						--tempcol;
                        ++temprow;
						++wordno;
                        ++t_heaviest_r;
                        ++t_heaviest_c;
					}
					else
					{
						found = false;
						wordno = 0;
                        t_heaviest_r=0;
                        t_heaviest_c=0;
                        break;
					}
				}
                if(found == true)
                {
                    row_pos=r;
                    col_pos=c;
                    dir=4;
                    ++dia_b;
                }
			}
		}
	}
}
void find_diag_upleft( char grid[][16],  char word[], int & dia_b,int & t_heaviest_r,int & t_heaviest_c)
{
	bool found = false;
	int r = 0, c = 0; // r is row, c is column
	int wordno = 0;
    int length = strlen(word);
	for (r = 0; r < 15 ; ++r)
	{
		for (c = 0; c <15; ++c)
		{
			if (grid[r][c] == word[wordno])
			{
				int l = 0;
				for (int tempcol = c , temprow = r; l < length ; ++l)
				{
					if (grid[temprow][tempcol] == word[wordno])
					{
						found = true;
						--tempcol;
                        --temprow;
						++wordno;
                        ++t_heaviest_r;
                        ++t_heaviest_c;
					}
					else
					{
						found = false;
						wordno = 0;
                        t_heaviest_r=0;
                        t_heaviest_c=0;
                        break;
					}
				}
                if(found == true)
                {
                    row_pos=r;
                    col_pos=c;
                    dir=6;
                    ++dia_b;
                }
			}
		}
	}
}
void Markcoloured(int rowpos, int colpos,int direction, char word[], char telegrid[][16])
{
int wordlength = strlen(word);
if (direction==1)
{ 
 for (int i = col_pos,leter=0 ; leter<wordlength ;  ++i , ++leter)
 {
   telegrid[row_pos][i]= '\0';
 }
}
if (direction==5)
{ 
 for (int i=col_pos ,leter=0 ; leter < wordlength ;  --i , ++leter)
 {
   telegrid[row_pos][i] = '\0';
 }
}
if (direction==3)
{ 
 for (int i = row_pos, leter=0 ; leter<wordlength ;  i++ , ++leter)
 {
   telegrid[i][col_pos]= '\0';
 }
}
if (direction==7)
{ 
 for (int i = row_pos ,leter=0 ; leter < wordlength ;  i-- , ++leter)
 {
   telegrid[i][col_pos]= '\0';
 }
}
if (direction==8)
{ 
 for (int i = col_pos, j = row_pos ,leter=0 ; leter<wordlength ; ++i ,  j-- , ++leter)
 {
   telegrid[j][i] = '\0';
 }
}
if (direction==2)
{ 
 for (int x=col_pos,y=row_pos,leter=0 ; leter<wordlength ; ++x,  ++y , ++leter)
 {
   telegrid[y][x] = '\0';
 }
}
if (direction==4)
{ 
 for (int x=col_pos ,y=row_pos ,leter=0 ; leter<wordlength ; --x,  ++y , ++leter)
 {
   telegrid[y][x] = '\0';
 }
}
if (direction==6)
{ 
 for (int x=col_pos , y=row_pos ,leter=0 ; leter<wordlength ; --x,  --y , ++leter)
 {
   telegrid[y][x] = '\0';
 }
}
}
void wordsearch(char grid[][16], char word[][15], char telegrid[][16],int & t_heaviest_r,int & t_heaviest_c,int & heaviest_r,int & heaviest_c,int counter[][16])
{
    int x=0;
    while (word[x][0]!='#')
    {
        find_hori_forward(grid,word[x],hori_f,t_heaviest_c);
        find_diag_downright(grid,word[x],dia_f,t_heaviest_r,t_heaviest_c);
        find_vertical_down(grid,word[x],ver_d,t_heaviest_r);
        find_diag_downleft(grid,word[x],dia_b,t_heaviest_r,t_heaviest_c);
        find_hori_backward(grid,word[x],hori_b,t_heaviest_c);
        find_diag_upleft(grid,word[x],dia_b,t_heaviest_r,t_heaviest_c);
        find_vertical_up(grid,word[x],ver_u,t_heaviest_r);
        find_diag_upright(grid,word[x],dia_f,t_heaviest_r,t_heaviest_c);
        colorxy(row_pos,col_pos,dir,word[x],counter);
        Markcoloured(row_pos,col_pos,dir,word[x],telegrid);
        if (t_heaviest_r > heaviest_r)
        {
            heaviest_r = t_heaviest_r;
        }
        if (t_heaviest_c > heaviest_c)
        {
            heaviest_c = t_heaviest_c;
        }
        if (istep==true) {_getch();}
        ++x;
    }
    
}
void teleWordFinder(char telegrid[][16],char teleword[])
{
    int g;
    g=0;
    for (int i =0; i < 15 ; ++i)
    {
        for (int j=0 ; j < 15 ; ++j)
        {
            if (telegrid[i][j] >= 'A' && telegrid[i][j] <= 'Z')
            {
                teleword[g]=telegrid[i][j];
                ++g;
            }
        }
    }
    teleword[g]= '\0';
}
int longest_len(char word[][15])
{
    int h = 0;
    int max=0;
    int v=0;
    while ( word[h][0]!= '#')
    {
        v = strlen(word[h]);
        if (v > max) { max = v;}
        ++h;
    }
    return max;
}
int shortest_len(char word[][15])
{
    int h = 0;
    int min=14;
    int v;
    while ( word[h][0]!= '#')
    {
        v = strlen(word[h]);
        if (v < min) { min = v;}
        ++h;
    }
    return min;
}
int avg_len(char word[][15])
{
    int h = 0 ;
    int avg,sum =0;
    int v;
    while ( word[h][0] != '#')
    {
        v = strlen(word[h]);
        sum = sum + v;
        ++h;
    }
    avg = sum/h;
    return avg;
}
int telewordscatter(char telegrid[][16])
{
    int count=0,x=0;
    for (int i=0;i<16;++i)
    {
        x=0;
        while (telegrid[i][x]=='\0' && x<15)
        {
            ++x;
        }
        if (telegrid[i][x]>='A' && telegrid[i][x]<='Z')
            {
                ++count;
            }

    }
    return count;
}

int main()
{
    clock_t begin,end;
    double ex_time;
    char in;
    char grid[16][16];
    char telegrid[16][16];
    char word[100][15];
    int counter[16][16];
	ifstream fin("D:\\hw3\\hw3\\sample puzzles\\teleword_1.txt");
    if (fin.fail()) {cout << "File not opened!! ";}
    else 
    { 
        for (int r = 0; r < 16; r++)
        {
            for (int c = 0; c < 16; c++)
            {
                counter[r][c] = 0;
            }
        }
        
    cout << endl << "Press s to solve the puzzle at once \n" << "Press t to solve the puzzle step by step \n" << "Press x to print Statistics .." << endl;
    cin >> in;
    while (in != 's' && in != 't' && in!= 'x')
    {
        cout << "wrong input .. enter again : ";
        cin >> in;
    }
    if (in=='t')
    {
        istep=true;
    }

system("cls");
begin = clock();
        char input;
        
        char buff[1000];
            
            int u,o;
            for (u=0;u<15;++u) // Grid read and store
            {
                for (o=0;o<15;++o)
                {
                    
                    fin >> input;
                    grid[u][o]=input; 
                    telegrid[u][o]=input;
                    cout << grid[u][o] ;
                    cout << " ";
                }
                telegrid[u][o] = '\0';
                grid[u][o] = '\0';
                
               cout << endl;
            }
            cout << endl;
            
        while (!fin.eof()) //fetching last line
        {
            fin.getline(buff,1000);
        }
        cout << buff << endl;;
        int i=0,k=0,j=0;
        while (buff[i]!='\0')
        {
            if (buff[i]!=',' && buff[i]!='.')
            {
                if (buff[i]>='A' && buff[i]<='Z')
                {
                word[k][j]=buff[i];
                ++j;
                } 
                  if (buff[i]>='a' && buff[i]<='z')
                {
                word[k][j]=buff[i]-32;
                ++j;
                }
            }
            else {
                word[k][j]='\0';
                j=0;
                ++k;
            }
            ++i;
        }
        word[k][j]='#';
        word[k][j+1]='\0';
}

wordsearch(grid,word,telegrid,t_heaviest_r,t_heaviest_c,heaviest_r,heaviest_c,counter);



char teleword[15];
teleWordFinder(telegrid,teleword);


for(int k=0; k< 20; k++)
{
    cout << endl;
}
cout << "Teleword: " << teleword << endl << endl;
end = clock();
ex_time = (double) (end-begin)/CLOCKS_PER_SEC;
if (in == 'x')
{
    cout << "Time to solve : " << ex_time << endl;
    cout << "Longest Word Length : " << longest_len(word) << endl;
    cout << "Shortest Word Length : " << shortest_len(word) << endl;
    cout << "Average Word Length : " << avg_len(word) << endl;
    cout << "Word Distribution : " << "Horizontal : " << hori_f+hori_b << " (" << hori_f << "," << hori_b << ") " << "verical : " << ver_u+ver_d << " (" << ver_u << "," << ver_d << ") " << "Diagonals : " << dia_f+dia_b << "(" << dia_f << "," << dia_b << ") " << endl ;
    cout << "Teleword Scatter : " << telewordscatter(telegrid) << endl; 
    cout << "Heaviest Row : " << heaviest_r << endl;
    cout << "Heaviest Column : " << heaviest_c << endl;
}
fin.close();
}



