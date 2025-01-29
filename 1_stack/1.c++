// #include <stack>
// bool findRedundantBrackets(string &s)
// {  
//     stack<char> st;

    
//     for(int i=0;i<s.length();i++)
//     {
//         char ch=s[i];
//         if(ch=='(' || '+' || '-' || '*' || '/' )
//         {
//             st.push(ch);
//         }
//         else  if(ch==')') //  closing bracket
//         {
//            if(st.top() == '+' || '-' || '*' || '/')
//            {
//                while(st.top()!='(' ) // check
//                {
//                    st.pop();
//                }
//                st.pop();
//            }
//            else{
//                return true;
//            }
//         }

//     }
//     return false;
// }
