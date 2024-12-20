a.out: 
	g++ main.cpp      	        	\
		objects/scene.cpp       	\
		objects/object.cpp      	\
		objects/button.cpp      	\
		objects/sphere.cpp      	\
		objects/light.cpp       	\
		objects/lightManager.cpp	\
		vectors/vector.cpp  		\
		vectors/vectorDec.cpp 		\
		vectors/vectorPol.cpp 		\
		vectors/vector3D.cpp 		\
		color.cpp               	\
		GrLib/GrLib.cpp         	\
		tests/testSimple2D.cpp  	\
		tests/testSimple3D.cpp  	\
		tests/testFollowMouse.cpp  	\
		tests/testButtonControl.cpp	\
		-Wno-narrowing          	\
		-Wno-unused-parameter		\
		-lsfml-graphics -lsfml-window -lsfml-system \
		-D _DEBUG -ggdb3 -Wall -Wextra -Waggressive-loop-optimizations -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 #-Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

# -Weffc++
# warning: ‘class Object’ has pointer data members [-Weffc++]

# -Wconversion 

# -Wshadow
# warning: declaration of ‘isDraw’ shadows a member of ‘Button’ [-Wshadow]
#   12 | Button::Button (bool isDraw, const VectorDec& init_corner, const VectorDec& init_size, const Color& init_color)

