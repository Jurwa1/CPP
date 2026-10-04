#include <iostream>
#include <string>

void Func(int* arr, size_t Size, int*& MinPTR, int*& MaxPTR, int& Min, int& Max);
void Swap(int& MinPTR, int& MaxPTR, int Min, int Max);

int main() {
	int arr[] = { 10, -5, 42, 7, 0 };
	size_t Size{ std::size(arr) };
	int* MinPTR = nullptr;
	int* MaxPTR = nullptr;
	int Min{ 0 };
	int Max{ 0 };

	if (Size != 0) {
		Func(arr, Size, MinPTR, MaxPTR, Min, Max);
		Swap(*MinPTR, *MaxPTR, Min, Max);
	}

	for (size_t i{ 0 }; i < Size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void Func(int* arr, size_t Size, int*& MinPTR, int*& MaxPTR, int& Min, int& Max) {

	for (int i{ 0 }; i != Size; ++i) {
		int Help{ arr[i] };

		if (Help < Min) {
			Min = Help;
			MinPTR = &arr[i];
		}

		if (Help > Max) {
			Max = Help;
			MaxPTR = &arr[i];
		}
	}
	
}

void Swap(int& MinPTR, int& MaxPTR, int Min, int Max) {
	MaxPTR = Min;
	MinPTR = Max;
}