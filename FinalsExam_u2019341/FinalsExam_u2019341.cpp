
#include <iostream>
using namespace std;
void tableLRU();

void tableLFU();



template<typename T>

class LRU {

protected:



T * Most;
T * Least;
char Max = 3;
 T memory[3];

public:




	void initialize()
	{

		for (int i = 0; i < Max; i++)
		{
			memory[i] = '\0';
		}



	}
	void assign(T input)
	{


		if (memory[0] == input)
		{

			Most = &memory[0];

		}

		else if (memory[0] != input)
		{
			char old = memory[0];

			char New;

			memory[0] = input;

			Most = &memory[0];


			for (int i = 1; i < Max; i++)
			{
				New = old;

				old = memory[i];

				memory[i] = New;


				if (memory[i] == input)
				{

					break;
					
				}

			}

		}

		for (int i = 0; i < Max; i++)
		{


			if (memory[i] != ' ')
			{

				Least = &memory[i];
			}

		}


	
	

	}
	
	

	void display()
	{
		cout << "Most recently used page" << '\n'<<*Most << endl;
		cout << "Least Recently Used Page" << '\n' << *Least << endl;
		cout << "Memory contained in Buffers"<<endl;
		for (int i=0; i < Max; i++)
		{

			cout << memory[i];


		}


	}


};

template<typename A>


class LFU {

private:


	A memory[3] = {'\0','\0','\0'};
	int frequency[3] = { 0,0,0 };
	int Max = 3;

public:
	

	void assign(A choice)
	{
		bool temp = false;

		for (int i = 0; i < Max;i++)
		{
			if (memory[i] == choice)
			{
				frequency[i]++;
				temp = true;
				break;
			}

			else if (   memory[i] != choice &&memory[i]=='\0')
			{

				memory[i] = choice;
				frequency[i]++;
				temp = true;
				break;

			}

		}

		if (temp == false)
		{
			char min = frequency[0];

			for (int i = 0; i < Max; i++)
			{
				if (frequency[i] < min)

				{
					min = frequency[i];

					break;


				}


			}

			for (int i = 0; i < Max; i++)
			{
				if (frequency[i] == min)

				{
					memory[i] = choice;
					frequency[i] = 1;
					break;


				}

			}

		}

	}




	void display()
	{
		cout << "Memory Buffer Contains" << '\n';
			for (int i = 0; i < Max; i++)
		{
			cout << memory[i]<<'\n';
		}
		cout << "Frequency Buffer Contains"<< '\n';

			for (int i = 0; i < Max; i++)
		{
			cout << frequency[i]<<'\n';
		                  
			} 
		

	}
};

int main()
{

	char choice = ' ';
	cout << "1:Least Recenty Used" << endl;
	cout << "2:Least Frequently Used" << endl;
	cout << "Which algorithim do you want to use,LRU or LFU" << endl;
	cin >> choice;

	switch (choice)
	{
	case '1':
	{
		tableLRU();


	}
	case '2':
	{

		tableLFU();
	}
}

}
int numbers()
{

	int choice;

	cout << "Enter Number from 1 to 9" << endl;

	cin >> choice;

	if (choice <= 9)
	{
		return choice;
	}
	else if (choice > 9)
	{
		cout << "wrong Value" << endl;

		main();

	}


}
char alphabets()
	{
		char temp;

		cout << "Enter alphabets,a to j" << endl;

		cin >> temp;

		if (temp == 'a' || 'b' || 'c' || 'd' || 'e' || 'f' || 'g' || 'h' || 'i' || 'j')
		{

			return temp;

		}

		else
		{

			cout << "Wrong Value" << endl;

			main();
		}


	}
void tableLRU()
{
	char Not = ' ';
	
	char temp;
	char loop = ' ';
	LRU<int>num;
	LRU<char>alpha;
	cout << "1:Numbers" << endl;
	cout << "2:Alphabets" << endl;

	cout << "Enter which notation will you be using" << endl;
	cin >> Not;

	switch (Not)

	{
	case '1':


		while (loop != 'n')
		{
			cout <<'\n' <<"Do you wish to add values" << endl;
			cin >> loop;

			if (loop == 'n')
			{
				break;
			}

			int temp;

			temp=numbers();

			num.assign(temp);
		
			num.display();

			
		}
	case '2':
	{

		while (loop != 'n')
		{
			cout << "Do you wish to add values" << endl;
			cin >> loop;

			if (loop == 'n')
			{
				break;
			}
			char temp;

			temp=alphabets();

			alpha.assign(temp);

			alpha.display();

		}
	}

	}


}


void tableLFU()
{


	char Swap = ' ';

	char temp;
	char loop = ' ';
	LFU<int>Numbers;
	LFU<char>characters;
	cout << "1:Numbers" << endl;
	cout << "2:Alphabets" << endl;

	cout << "Enter which notation will you be using" << endl;
	cin >> Swap;

	switch (Swap)

	{
	case '1':


		while (loop != 'n')
		{
			cout << "Do you wish to add values" << endl;
			cin >> loop;

			if (loop == 'n')
			{
				break;
			}

			int temp;

			temp = numbers();

			Numbers.assign(temp);

			Numbers.display();


		}
	case '2':
	{

		while (loop != 'n')
		{
			cout << "Do you wish to add values" << endl;
			cin >> loop;

			if (loop == 'n')
			{
				break;
			}
			char temp;

			temp = alphabets();

			characters.assign(temp);

			characters.display();

		}
	}

	}


}