//// ** FORWARD DECLARATIONS
//struct InfoForView;
//enum AnimationType; // TODO: Definire questo animationState da qualche parte! (Forse qui)
//// ** End

template<typename Policy>
class ViewMiddleLayer: private Policy {

	// --> Intarface member function that it's mandatory to implement in the "Policy" <--
	// ** NOTA:
	/*
		C++03 7.3.3 The using declaration:
		"...If the name is that of an overloaded member function, then all functions named shall be accessible.".
	*/
	using Policy::Init; // <-- With "InfoForView" as parameter!
	using Policy::Draw;
	using Policy::EndGame;
	using Policy::StartAnimation; // <-- With "AnimationType" as parameter!

	// TODO: Implementing ViewMiddleLayer
	// NOTA: Policy::Init(InfoForView); // <-- For the declaration of the function isn't necessary the definition of the object
	// NOTA: Policy::StartAnimation(AnimationType);
};