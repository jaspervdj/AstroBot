/* Practicum 5, Jasper Van der Jeugt
 * BinarySearchTree.h
 */
#ifndef H_BINARY_SEARCH_TREE
#define H_BINARY_SEARCH_TREE

#include <string>

/*
	Deze klasse stelt een node voor. 
	Deze houdt bepaalde referenties naar andere nodes bij en zijn eigen waarde.
*/
class TreeElement {
public:
	// Pointers, respectievelijk naar de root van de linkse subtree, root van de rechtse subtree en de parent node.
	TreeElement *left, *right, *parent;
	// The actual value of this node.
	std::string key;


	// Constructors
	TreeElement();
	TreeElement(const std::string &k);

	// Destructors
	~TreeElement();
};


/*
	Deze klasse stelt de BinarySearchTree en de nodige logica voor.
	Alle gebruikte TreeElements hangen direct of indirect vast aan de root.
*/
class BinarySearchTree{
public:

	// Constructor
	BinarySearchTree();

	// Kijkt of de boom leeg is
	bool isEmpty();

	// Voegt een element toe aan de boom met als value de opgegeven string.
	// Geeft true terug als het gelukt is, geeft false terug, wanneer de waarde zich al in de boom bevindt.
	bool insert(const std::string &key);

	// Gebruikt het binair zoek algoritme om de boom te doorzoeken naar het bestaan van de opgegeven string
	bool contains(const std::string& key);

	// Geeft een array van strings terug die het interval voorstellen van de start tot en met de stop string
	std::string* getValuesInRange(const std::string &start, const std::string &stop, int* arraySize);

	// Geeft een array van strings terug die alle elementen van de boom bevat
	std::string* getAllValues(int* arraySize);

	// destructor
	~BinarySearchTree();

private:
	// Pointer naar de root van de boom
	TreeElement* root;
	// Diepte van de boom
	double depth;

	// Doorzoek de boom en geef de pointer naar het gezochte TreeElement terug. 
	// Indien niet gevonden, geef NULL terug.
	TreeElement* get(const std::string &key);


	// Eigen private methodes

    /* We prefer to keep track of the actual size of the tree instead of the
     * depth. */
    int size;

    /* Function to recursively add all elements of the tree to an array. */
    void addToArray(TreeElement *element, std::string *array, int *position)
            const;

    /* Function to recursively add all elements of the tree in a certain range
     * to an array. */
    void addToArray(TreeElement *element, std::string **array, int *arraySize,
            int *position, const std::string &start, const std::string &stop)
            const;
};

#endif
