#include<iostream>
#include<string>
using namespace std;

struct Contact
{
	string name;
	string phoneNumber;
	Contact* next;
};

class contactList {
private:
	Contact* Head;
	Contact* Tail;
public:
	contactList()
	{
		Head = NULL;
		Tail = NULL;
	}
	void addContact(string name, string phoneNumber)
	{
		Contact* temp = new Contact;
		temp->name = name;
		temp->phoneNumber = phoneNumber;
		temp->next = NULL;
		if (Head == NULL)
			Head = Tail = temp;
		else
		{
			Tail->next = temp;
			Tail = temp;
		}
	}

	void displayContact()
	{
		if (Head == NULL)
			cout << "contact is empty";
		else
		{
			cout << "Contact list: " << endl;
			for (Contact* k = Head; k != NULL; k = k->next)
			{
				cout << "Name: " << k->name << ", Phone: " << k->phoneNumber << endl;
			}
		}
	}
	void swapContacts(Contact* contact1, Contact* contact2) {
		string tempName = contact1->name;
		string tempPhoneNumber = contact1->phoneNumber;

		contact1->name = contact2->name;
		contact1->phoneNumber = contact2->phoneNumber;

		contact2->name = tempName;
		contact2->phoneNumber = tempPhoneNumber;
	}
	void sortByName()
	{
		for (Contact* k = Head; k->next!= NULL; k = k->next)
		{
			for (Contact* p = Head->next; p != NULL; p = p->next)
			{
				if (p->name < k->name)
					swapContacts(k, p);
			}
		}
	}
};

int main()
{
	contactList l;
	l.addContact("Bob", "091111");
	l.addContact("Billy", "095555");
	l.addContact("Andy", "093333");
	l.addContact("Chris", "092222");
	l.displayContact();
	l.sortByNumber();
	l.displayContact();
	return 0;
}
