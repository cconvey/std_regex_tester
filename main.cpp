#include <regex>
#include <iostream>
#include <string>

using namespace std;

int main( int argc, const char* argv[] ) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <regex> <test-string>" << endl;
        return 1;
    }

    const string re_str( argv[1] );
    const string test_str( argv[2] );

    const regex re{ re_str };

    cout << "REGEX: '" << re_str << "'" << endl;
    cout << "   re.mark_count() = " << re.mark_count() << endl;
    cout << endl;

    cout << "TEST-STRING: '" << test_str << "'" << endl;
    cout << endl;

    smatch m;
    const bool matched = regex_match( test_str, m, re );
    cout << "regex_match returned " << matched << endl;

    cout << "m.ready() = " << m.ready() << endl;
    cout << "m.empty() = " << m.empty() << endl;
    cout << "m.size() = " << m.size() << endl;

    if (! matched) {
        return 0;
    }

    for (size_t i = 0; i <= m.size(); ++i) {
        cout << "m.length  (" << i << ") = "  << m.length  (i) << endl;
        cout << "m.position(" << i << ") = "  << m.position(i) << endl;
        cout << "m.str     (" << i << ") = '" << m.str     (i) << "'" << endl;
        cout << "m.prefix  () = '" << m.prefix() << "'" << endl;
        cout << "m.suffix  () = '" << m.suffix() << "'" << endl;

        const auto & sm = m[i];
        cout << "m[" << i << "]            = '" << m[i] << "'" << endl;
        cout << endl;
    }

    return 0;
}
