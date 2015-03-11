#include "Matrix4.h"
#include "Console\ConsolePrint.h"

namespace Engine
{

    void UnitTest_Matrix()
    {
        // Addition

        Matrix4 a, b, c;

        float a_data[] = {  1.0f, 2.0f, 3.0f, 4.0f,
                            5.0f, 6.0f, 7.0f, 8.0f,
                            9.0f, 10.0f, 11.0f, 12.0f,
                            13.0f, 14.0f, 15.0f, 16.0f };

        float b_data[] = {  10.0f, 11.0f, 12.0f, 13.0f,
                            14.0f, 15.0f, 16.0f, 17.0f,
                            18.0f, 19.0f, 20.f, 21.0f,
                            22.0f, 23.0f, 24.0f, 25.0f }; 

        float c_data[] = {  180.0f, 190.f,    200.f,    210.f,
                            436.f,    462.f,    488.f,    514.f,
                            692.f,    734.f,    776.f,    818.f,
                            948.f,   1006.f,   1064.f,   1122.f };

        a.setFromArray(a_data);
        b.setFromArray(b_data);
        c.setFromArray(c_data);
        Matrix4 mul = a*b;
        
        if (Matrix4::isEqual(mul, c))
            DEBUG_PRINT("Multiplication test pass\n");


        Matrix4 e, e_inv, test;
        float e_data[] = { 27.0f, 19.0f, 10.0f, 40.0f,
                           17.0f, 9.0f, 14.0f, 15.0f,
                           5.0f, 15.0f, 18.0f, 2.0f,
                           27.0f, 10.0f, 9.0f, 25.0f };
       
        float e_inv_data[] = { -0.0606992f, -0.0987356f, 0.0336834f, 0.1536654f,
                                0.0091550f, -0.2309818f, 0.1172874f, 0.1145581f,
                                0.0024528f, 0.2060388f, -0.0440475f, -0.1240240f,
                                0.0610102f, 0.1248532f, -0.0674359f, -0.1271333f };

        e.setFromArray(e_data);
        e_inv.setFromArray(e_inv_data);
        
        e.getInverse(test);
        
        if (Matrix4::isEqual(test,e_inv))
            DEBUG_PRINT("Inverse test pass\n");

        int t;
        std::cin >> t;
    }

}