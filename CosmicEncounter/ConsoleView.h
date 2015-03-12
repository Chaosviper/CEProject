#include "InfoForView.h"

// ** FORWARD DECLARATIONS
enum AnimationType; // TODO: Definire questo animationState da qualche parte! (Forse qui)
// ** End

class ConsoleView
{
	CallbackFunctionOnEndAnimation callbackOnEndAnimation;

public:
	void Init(InfoForView gameInfo); // <-- For the declaration of the function isn't necessary the definition of the object
	void Draw();
	void EndGame();
	void StartAnimation(AnimationType animationToStart);

	ConsoleView();
	~ConsoleView();
};

