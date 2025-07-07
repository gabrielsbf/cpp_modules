#include <string>
#include <iostream>
#include "includes/Animal.hpp"
#include "includes/Cat.hpp"
#include "includes/Dog.hpp"
#include "includes/Brain.hpp"

#define NB_ANIMALS 5

void	testAnimalArray(void)
{
	std::cout <<  "*******************************" << std::endl
		<< "Creating Animal Array" << std::endl
		<<  "*******************************" << std::endl << std::endl;
	Animal	* animalArray[NB_ANIMALS + 1];
	animalArray[NB_ANIMALS] = NULL;

	std::cout << "** Creating a array of " << NB_ANIMALS << " animals: " 
		<< NB_ANIMALS / 2 << " cats and "
		<< NB_ANIMALS - (NB_ANIMALS / 2) << " dogs." << std::endl << std::endl;

	for (int i = 0; i < NB_ANIMALS / 2; i++)
		animalArray[i] = new Cat();

	for (int i = NB_ANIMALS / 2; i < NB_ANIMALS; i++)
		animalArray[i] = new Dog();
	
	std::cout << std::endl << "** The cats and dogs are loud..." << std::endl;
	for (int i = 0; animalArray[i]; i++)
		{
            std::cout << "Animal [" << i << "/" << NB_ANIMALS - 1 << "] is a "
            << animalArray[i]->getType() << ": ";
            animalArray[i]->makeSound();
        }
	
	std::cout << std::endl << "** Destroying the Animals Array!"<< std::endl;
	for (int i = 0; animalArray[i]; i++)
		delete animalArray[i];
	std::cout << std::endl;
}

void testCopyCat(void)
{
	std::cout <<  "*******************************" << std::endl
		<< "\tCOPY CAT TEST" << std::endl
		<<  "*******************************" << std::endl << std::endl
		<< "** Creating cat." << std::endl;
	Cat * meow = new Cat();

	std::cout << std::endl << "** Putting ideas in meow's brain..." << std::endl;
	meow->getBrain()->setIdea(0, "I think I have a hairball...");
	meow->getBrain()->setIdea(1, "I need to cough the hairball up...");
	meow->getBrain()->setIdea(2, "Human, clean that up, will you?");

	std::cout << "meow idea 0: \"" << meow->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "meow idea 1: \"" << meow->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "meow idea 2: \"" << meow->getBrain()->getIdea(2) << "\"" << std::endl;

	std::cout << std::endl << "** Creating a copy of \"meow\" cat" << std::endl;
	Cat * copyCat = new Cat(*meow);

	std::cout << std::endl << "** CopyCat should have the same ideas as meow." << std::endl;
	std::cout << "CopyCat idea0: \"" << copyCat->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyCat idea1: \"" << copyCat->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "CopyCat idea2: \"" << copyCat->getBrain()->getIdea(2) << "\"" << std::endl;

	std::cout << std::endl << "** Putting new ideas in meow's brain..." << std::endl;
	meow->getBrain()->setIdea(0, "Where is that mouse??");
	meow->getBrain()->setIdea(1, "I'm hungry.");
	meow->getBrain()->setIdea(2, "I shall outsmart that mouse!");

	std::cout << "meow idea 0: \"" << meow->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "meow idea 1: \"" << meow->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "meow idea 2: \"" << meow->getBrain()->getIdea(2) << "\"" << std::endl;
	
	std::cout << std::endl << "** CopyCat's ideas should not have changed." << std::endl;
	std::cout << "CopyCat idea0: \"" << copyCat->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyCat idea1: \"" << copyCat->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "CopyCat idea2: \"" << copyCat->getBrain()->getIdea(2) << "\"" << std::endl;

	std::cout << std::endl << "** Setting CopyCat = meow." << std::endl;
	*copyCat = *meow;

	std::cout << std::endl << "** CopyCat's ideas should have changed to meow's." << std::endl;
	std::cout << "CopyCat idea0: \"" << copyCat->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyCat idea1: \"" << copyCat->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "CopyCat idea2: \"" << copyCat->getBrain()->getIdea(2) << "\"" << std::endl;


	std::cout << std::endl << "** Deleting meow and CopyCat." << std::endl;
	delete meow;
	delete copyCat;
	std::cout << std::endl;
}

void testCopyDog(void)
{
	std::cout <<  "*******************************" << std::endl
		<< "\tCOPY DOG TEST" << std::endl
		<<  "*******************************" << std::endl << std::endl
		<< "** Creating dog" << std::endl;
	Dog * doggo = new Dog();
	std::cout << std::endl << "** Putting ideas in doggo's brain..." << std::endl;
	doggo->getBrain()->setIdea(0, "Food! Food! Food!");
	doggo->getBrain()->setIdea(1, "Human! Human! Human!");

	std::cout << "doggo idea 0: \"" << doggo->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "doggo idea 1: \"" << doggo->getBrain()->getIdea(1) << "\"" << std::endl;

	std::cout << std::endl << "** Creating a copy of \"doggo\" dog." << std::endl;
	Dog * copyDog = new Dog(*doggo);
	
	std::cout << std::endl << "** CopyDog should have the same ideas as doggo." << std::endl;
	std::cout << "CopyDog idea0: \"" << copyDog->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyDog idea1: \"" << copyDog->getBrain()->getIdea(1) << "\"" << std::endl;
	
	std::cout << std::endl << "** Putting new ideas in doggo's brain..." << std::endl;
	doggo->getBrain()->setIdea(0, "Fetch! Fetch! Fetch!");
	doggo->getBrain()->setIdea(1, "Bark! Bark! Bark!");

	std::cout << "doggo idea 0: \"" << doggo->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "doggo idea 1: \"" << doggo->getBrain()->getIdea(1) << "\"" << std::endl;
	
	std::cout << std::endl << "** CopyDog's ideas should not have changed." << std::endl;
	std::cout << "CopyDog idea0: \"" << copyDog->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyDog idea1: \"" << copyDog->getBrain()->getIdea(1) << "\"" << std::endl;

	std::cout << std::endl << "** Setting CopyDog = doggo." << std::endl;
	*copyDog = *doggo;

	std::cout << std::endl << "** CopyDog's ideas should have changed to doggo's." << std::endl;
	std::cout << "CopyDog idea0: \"" << copyDog->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyDog idea1: \"" << copyDog->getBrain()->getIdea(1) << "\"" << std::endl;

	std::cout << std::endl << "** Deleting doggo and CopyDog." << std::endl;
	delete doggo;
	delete copyDog;
	std::cout << std::endl;
}