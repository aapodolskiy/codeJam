#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::max;

const int number_of_dividers[1001] = {0, 1, 2, 2, 3, 2, 4, 2, 4, 3, 4, 2, 6, 2, 4, 4, 5, 2, 6, 2, 6, 4, 4, 2, 8, 3, 4, 4, 6, 2, 8, 2, 6, 4, 4, 4, 9, 2, 4, 4, 8, 2, 8, 2, 6, 6, 4, 2, 10, 3, 6, 4, 6, 2, 8, 4, 8, 4, 4, 2, 12, 2, 4, 6, 7, 4, 8, 2, 6, 4, 8, 2, 12, 2, 4, 6, 6, 4, 8, 2, 10, 5, 4, 2, 12, 4, 4, 4, 8, 2, 12, 4, 6, 4, 4, 4, 12, 2, 6, 6, 9, 2, 8, 2, 8, 8, 4, 2, 12, 2, 8, 4, 10, 2, 8, 4, 6, 6, 4, 4, 16, 3, 4, 4, 6, 4, 12, 2, 8, 4, 8, 2, 12, 4, 4, 8, 8, 2, 8, 2, 12, 4, 4, 4, 15, 4, 4, 6, 6, 2, 12, 2, 8, 6, 8, 4, 12, 2, 4, 4, 12, 4, 10, 2, 6, 8, 4, 2, 16, 3, 8, 6, 6, 2, 8, 6, 10, 4, 4, 2, 18, 2, 8, 4, 8, 4, 8, 4, 6, 8, 8, 2, 14, 2, 4, 8, 9, 2, 12, 2, 12, 4, 4, 4, 12, 4, 4, 6, 10, 4, 16, 2, 6, 4, 4, 4, 16, 4, 4, 4, 12, 4, 8, 2, 12, 9, 4, 2, 12, 2, 8, 8, 8, 2, 12, 4, 6, 4, 8, 2, 20, 2, 6, 6, 6, 6, 8, 4, 8, 4, 8, 2, 18, 4, 4, 8, 9, 2, 8, 4, 12, 6, 4, 2, 16, 4, 8, 4, 6, 2, 16, 2, 10, 8, 4, 6, 12, 2, 4, 6, 16, 2, 8, 2, 6, 8, 8, 4, 18, 3, 8, 4, 6, 2, 12, 4, 8, 8, 4, 4, 18, 4, 4, 4, 10, 4, 12, 2, 12, 4, 8, 2, 16, 2, 4, 12, 6, 2, 8, 4, 14, 4, 8, 4, 15, 6, 4, 4, 8, 4, 16, 2, 6, 6, 4, 4, 20, 2, 6, 4, 12, 4, 12, 4, 8, 8, 4, 2, 12, 2, 12, 8, 12, 2, 8, 4, 6, 8, 4, 2, 24, 3, 4, 6, 12, 4, 8, 2, 10, 6, 8, 4, 12, 2, 8, 8, 8, 4, 16, 2, 12, 4, 4, 2, 16, 8, 4, 6, 6, 2, 16, 4, 12, 4, 4, 4, 18, 2, 4, 8, 15, 2, 8, 4, 6, 10, 8, 4, 16, 2, 8, 4, 6, 4, 12, 4, 12, 4, 8, 2, 24, 2, 4, 6, 8, 6, 8, 4, 6, 8, 8, 2, 20, 2, 8, 8, 6, 4, 8, 2, 16, 9, 8, 2, 12, 4, 4, 4, 14, 2, 18, 4, 6, 4, 4, 8, 16, 2, 4, 8, 12, 2, 16, 2, 10, 8, 4, 2, 18, 4, 8, 4, 8, 4, 8, 6, 12, 6, 4, 2, 24, 4, 4, 8, 9, 4, 12, 2, 8, 4, 12, 2, 12, 4, 8, 12, 10, 4, 8, 2, 12, 4, 4, 2, 24, 4, 8, 6, 6, 2, 16, 4, 10, 8, 4, 4, 12, 4, 8, 4, 16, 2, 12, 2, 6, 12, 4, 4, 20, 3, 8, 6, 12, 4, 8, 4, 8, 4, 4, 6, 24, 2, 4, 4, 12, 4, 16, 2, 6, 6, 12, 4, 16, 4, 4, 8, 6, 2, 12, 4, 20, 8, 4, 2, 12, 4, 4, 10, 8, 2, 16, 2, 12, 4, 8, 6, 21, 2, 6, 4, 12, 4, 8, 4, 8, 12, 4, 2, 18, 4, 8, 4, 10, 2, 16, 8, 6, 4, 8, 2, 24, 2, 8, 6, 6, 6, 8, 2, 12, 8, 8, 4, 18, 2, 4, 8, 16, 2, 8, 2, 12, 8, 4, 4, 20, 5, 4, 8, 6, 4, 24, 2, 8, 4, 4, 4, 12, 6, 8, 6, 16, 2, 8, 2, 12, 8, 8, 2, 20, 4, 12, 8, 6, 2, 8, 4, 10, 6, 8, 2, 24, 2, 4, 8, 8, 8, 12, 4, 6, 4, 8, 4, 24, 2, 4, 12, 9, 2, 8, 4, 16, 4, 8, 2, 18, 4, 8, 4, 10, 4, 16, 2, 6, 12, 4, 4, 16, 4, 4, 4, 18, 2, 16, 4, 14, 8, 4, 4, 12, 2, 8, 6, 8, 4, 16, 8, 6, 4, 4, 2, 30, 4, 6, 4, 6, 6, 12, 2, 16, 7, 8, 4, 12, 2, 4, 12, 12, 4, 12, 2, 12, 8, 8, 2, 16, 4, 4, 6, 12, 4, 16, 2, 10, 4, 8, 4, 24, 2, 4, 8, 16, 2, 8, 4, 6, 12, 4, 4, 18, 2, 16, 4, 6, 2, 12, 6, 8, 8, 4, 4, 24, 4, 8, 8, 15, 4, 8, 2, 6, 4, 8, 4, 24, 4, 4, 8, 6, 2, 16, 4, 18, 6, 4, 4, 12, 8, 8, 4, 8, 2, 20, 2, 12, 4, 8, 4, 20, 4, 4, 12, 12, 2, 8, 2, 8, 12, 8, 2, 18, 2, 8, 4, 14, 6, 8, 4, 12, 8, 4, 2, 32, 3, 4, 4, 6, 6, 12, 6, 10, 4, 12, 4, 12, 2, 8, 12, 8, 2, 16, 2, 12, 8, 4, 2, 24, 4, 4, 6, 12, 4, 16, 4, 8, 6, 8, 8, 12, 2, 4, 4, 20, 2, 18, 2, 12, 8, 4, 2, 16, 4, 8, 10, 6, 4, 8, 4, 16, 8, 4, 4, 27, 4, 8, 8, 8, 4, 8, 2, 6, 6, 16, 2, 20, 4, 4, 8, 6, 4, 16, 2, 16, 4, 4, 4, 24, 6, 4, 6, 12, 2, 16, 6, 6, 4, 4, 8, 24, 2, 8, 4, 12, 2, 8, 4, 10, 16, 8, 2, 12, 4, 12, 4, 16, 2, 12, 4, 6, 8, 4, 4, 28, 3, 8, 6, 6, 4, 16, 2, 12, 8, 8, 2, 18, 4, 4, 12, 10, 2, 8, 4, 18, 6, 4, 2, 16, 4, 8, 8, 12, 4, 24, 2, 12, 4, 8, 4, 12, 2, 4, 8, 16};

const int dividers_map[1001][32] = {
  { 0 },
  { 1 },
  { 1, 2 },
  { 1, 3 },
  { 1, 2, 4 },
  { 1, 5 },
  { 1, 2, 3, 6 },
  { 1, 7 },
  { 1, 2, 4, 8 },
  { 1, 3, 9 },
  { 1, 2, 5, 10 },
  { 1, 11 },
  { 1, 2, 3, 4, 6, 12 },
  { 1, 13 },
  { 1, 2, 7, 14 },
  { 1, 3, 5, 15 },
  { 1, 2, 4, 8, 16 },
  { 1, 17 },
  { 1, 2, 3, 6, 9, 18 },
  { 1, 19 },
  { 1, 2, 4, 5, 10, 20 },
  { 1, 3, 7, 21 },
  { 1, 2, 11, 22 },
  { 1, 23 },
  { 1, 2, 3, 4, 6, 8, 12, 24 },
  { 1, 5, 25 },
  { 1, 2, 13, 26 },
  { 1, 3, 9, 27 },
  { 1, 2, 4, 7, 14, 28 },
  { 1, 29 },
  { 1, 2, 3, 5, 6, 10, 15, 30 },
  { 1, 31 },
  { 1, 2, 4, 8, 16, 32 },
  { 1, 3, 11, 33 },
  { 1, 2, 17, 34 },
  { 1, 5, 7, 35 },
  { 1, 2, 3, 4, 6, 9, 12, 18, 36 },
  { 1, 37 },
  { 1, 2, 19, 38 },
  { 1, 3, 13, 39 },
  { 1, 2, 4, 5, 8, 10, 20, 40 },
  { 1, 41 },
  { 1, 2, 3, 6, 7, 14, 21, 42 },
  { 1, 43 },
  { 1, 2, 4, 11, 22, 44 },
  { 1, 3, 5, 9, 15, 45 },
  { 1, 2, 23, 46 },
  { 1, 47 },
  { 1, 2, 3, 4, 6, 8, 12, 16, 24, 48 },
  { 1, 7, 49 },
  { 1, 2, 5, 10, 25, 50 },
  { 1, 3, 17, 51 },
  { 1, 2, 4, 13, 26, 52 },
  { 1, 53 },
  { 1, 2, 3, 6, 9, 18, 27, 54 },
  { 1, 5, 11, 55 },
  { 1, 2, 4, 7, 8, 14, 28, 56 },
  { 1, 3, 19, 57 },
  { 1, 2, 29, 58 },
  { 1, 59 },
  { 1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60 },
  { 1, 61 },
  { 1, 2, 31, 62 },
  { 1, 3, 7, 9, 21, 63 },
  { 1, 2, 4, 8, 16, 32, 64 },
  { 1, 5, 13, 65 },
  { 1, 2, 3, 6, 11, 22, 33, 66 },
  { 1, 67 },
  { 1, 2, 4, 17, 34, 68 },
  { 1, 3, 23, 69 },
  { 1, 2, 5, 7, 10, 14, 35, 70 },
  { 1, 71 },
  { 1, 2, 3, 4, 6, 8, 9, 12, 18, 24, 36, 72 },
  { 1, 73 },
  { 1, 2, 37, 74 },
  { 1, 3, 5, 15, 25, 75 },
  { 1, 2, 4, 19, 38, 76 },
  { 1, 7, 11, 77 },
  { 1, 2, 3, 6, 13, 26, 39, 78 },
  { 1, 79 },
  { 1, 2, 4, 5, 8, 10, 16, 20, 40, 80 },
  { 1, 3, 9, 27, 81 },
  { 1, 2, 41, 82 },
  { 1, 83 },
  { 1, 2, 3, 4, 6, 7, 12, 14, 21, 28, 42, 84 },
  { 1, 5, 17, 85 },
  { 1, 2, 43, 86 },
  { 1, 3, 29, 87 },
  { 1, 2, 4, 8, 11, 22, 44, 88 },
  { 1, 89 },
  { 1, 2, 3, 5, 6, 9, 10, 15, 18, 30, 45, 90 },
  { 1, 7, 13, 91 },
  { 1, 2, 4, 23, 46, 92 },
  { 1, 3, 31, 93 },
  { 1, 2, 47, 94 },
  { 1, 5, 19, 95 },
  { 1, 2, 3, 4, 6, 8, 12, 16, 24, 32, 48, 96 },
  { 1, 97 },
  { 1, 2, 7, 14, 49, 98 },
  { 1, 3, 9, 11, 33, 99 },
  { 1, 2, 4, 5, 10, 20, 25, 50, 100 },
  { 1, 101 },
  { 1, 2, 3, 6, 17, 34, 51, 102 },
  { 1, 103 },
  { 1, 2, 4, 8, 13, 26, 52, 104 },
  { 1, 3, 5, 7, 15, 21, 35, 105 },
  { 1, 2, 53, 106 },
  { 1, 107 },
  { 1, 2, 3, 4, 6, 9, 12, 18, 27, 36, 54, 108 },
  { 1, 109 },
  { 1, 2, 5, 10, 11, 22, 55, 110 },
  { 1, 3, 37, 111 },
  { 1, 2, 4, 7, 8, 14, 16, 28, 56, 112 },
  { 1, 113 },
  { 1, 2, 3, 6, 19, 38, 57, 114 },
  { 1, 5, 23, 115 },
  { 1, 2, 4, 29, 58, 116 },
  { 1, 3, 9, 13, 39, 117 },
  { 1, 2, 59, 118 },
  { 1, 7, 17, 119 },
  { 1, 2, 3, 4, 5, 6, 8, 10, 12, 15, 20, 24, 30, 40, 60, 120 },
  { 1, 11, 121 },
  { 1, 2, 61, 122 },
  { 1, 3, 41, 123 },
  { 1, 2, 4, 31, 62, 124 },
  { 1, 5, 25, 125 },
  { 1, 2, 3, 6, 7, 9, 14, 18, 21, 42, 63, 126 },
  { 1, 127 },
  { 1, 2, 4, 8, 16, 32, 64, 128 },
  { 1, 3, 43, 129 },
  { 1, 2, 5, 10, 13, 26, 65, 130 },
  { 1, 131 },
  { 1, 2, 3, 4, 6, 11, 12, 22, 33, 44, 66, 132 },
  { 1, 7, 19, 133 },
  { 1, 2, 67, 134 },
  { 1, 3, 5, 9, 15, 27, 45, 135 },
  { 1, 2, 4, 8, 17, 34, 68, 136 },
  { 1, 137 },
  { 1, 2, 3, 6, 23, 46, 69, 138 },
  { 1, 139 },
  { 1, 2, 4, 5, 7, 10, 14, 20, 28, 35, 70, 140 },
  { 1, 3, 47, 141 },
  { 1, 2, 71, 142 },
  { 1, 11, 13, 143 },
  { 1, 2, 3, 4, 6, 8, 9, 12, 16, 18, 24, 36, 48, 72, 144 },
  { 1, 5, 29, 145 },
  { 1, 2, 73, 146 },
  { 1, 3, 7, 21, 49, 147 },
  { 1, 2, 4, 37, 74, 148 },
  { 1, 149 },
  { 1, 2, 3, 5, 6, 10, 15, 25, 30, 50, 75, 150 },
  { 1, 151 },
  { 1, 2, 4, 8, 19, 38, 76, 152 },
  { 1, 3, 9, 17, 51, 153 },
  { 1, 2, 7, 11, 14, 22, 77, 154 },
  { 1, 5, 31, 155 },
  { 1, 2, 3, 4, 6, 12, 13, 26, 39, 52, 78, 156 },
  { 1, 157 },
  { 1, 2, 79, 158 },
  { 1, 3, 53, 159 },
  { 1, 2, 4, 5, 8, 10, 16, 20, 32, 40, 80, 160 },
  { 1, 7, 23, 161 },
  { 1, 2, 3, 6, 9, 18, 27, 54, 81, 162 },
  { 1, 163 },
  { 1, 2, 4, 41, 82, 164 },
  { 1, 3, 5, 11, 15, 33, 55, 165 },
  { 1, 2, 83, 166 },
  { 1, 167 },
  { 1, 2, 3, 4, 6, 7, 8, 12, 14, 21, 24, 28, 42, 56, 84, 168 },
  { 1, 13, 169 },
  { 1, 2, 5, 10, 17, 34, 85, 170 },
  { 1, 3, 9, 19, 57, 171 },
  { 1, 2, 4, 43, 86, 172 },
  { 1, 173 },
  { 1, 2, 3, 6, 29, 58, 87, 174 },
  { 1, 5, 7, 25, 35, 175 },
  { 1, 2, 4, 8, 11, 16, 22, 44, 88, 176 },
  { 1, 3, 59, 177 },
  { 1, 2, 89, 178 },
  { 1, 179 },
  { 1, 2, 3, 4, 5, 6, 9, 10, 12, 15, 18, 20, 30, 36, 45, 60, 90, 180 },
  { 1, 181 },
  { 1, 2, 7, 13, 14, 26, 91, 182 },
  { 1, 3, 61, 183 },
  { 1, 2, 4, 8, 23, 46, 92, 184 },
  { 1, 5, 37, 185 },
  { 1, 2, 3, 6, 31, 62, 93, 186 },
  { 1, 11, 17, 187 },
  { 1, 2, 4, 47, 94, 188 },
  { 1, 3, 7, 9, 21, 27, 63, 189 },
  { 1, 2, 5, 10, 19, 38, 95, 190 },
  { 1, 191 },
  { 1, 2, 3, 4, 6, 8, 12, 16, 24, 32, 48, 64, 96, 192 },
  { 1, 193 },
  { 1, 2, 97, 194 },
  { 1, 3, 5, 13, 15, 39, 65, 195 },
  { 1, 2, 4, 7, 14, 28, 49, 98, 196 },
  { 1, 197 },
  { 1, 2, 3, 6, 9, 11, 18, 22, 33, 66, 99, 198 },
  { 1, 199 },
  { 1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 200 },
  { 1, 3, 67, 201 },
  { 1, 2, 101, 202 },
  { 1, 7, 29, 203 },
  { 1, 2, 3, 4, 6, 12, 17, 34, 51, 68, 102, 204 },
  { 1, 5, 41, 205 },
  { 1, 2, 103, 206 },
  { 1, 3, 9, 23, 69, 207 },
  { 1, 2, 4, 8, 13, 16, 26, 52, 104, 208 },
  { 1, 11, 19, 209 },
  { 1, 2, 3, 5, 6, 7, 10, 14, 15, 21, 30, 35, 42, 70, 105, 210 },
  { 1, 211 },
  { 1, 2, 4, 53, 106, 212 },
  { 1, 3, 71, 213 },
  { 1, 2, 107, 214 },
  { 1, 5, 43, 215 },
  { 1, 2, 3, 4, 6, 8, 9, 12, 18, 24, 27, 36, 54, 72, 108, 216 },
  { 1, 7, 31, 217 },
  { 1, 2, 109, 218 },
  { 1, 3, 73, 219 },
  { 1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110, 220 },
  { 1, 13, 17, 221 },
  { 1, 2, 3, 6, 37, 74, 111, 222 },
  { 1, 223 },
  { 1, 2, 4, 7, 8, 14, 16, 28, 32, 56, 112, 224 },
  { 1, 3, 5, 9, 15, 25, 45, 75, 225 },
  { 1, 2, 113, 226 },
  { 1, 227 },
  { 1, 2, 3, 4, 6, 12, 19, 38, 57, 76, 114, 228 },
  { 1, 229 },
  { 1, 2, 5, 10, 23, 46, 115, 230 },
  { 1, 3, 7, 11, 21, 33, 77, 231 },
  { 1, 2, 4, 8, 29, 58, 116, 232 },
  { 1, 233 },
  { 1, 2, 3, 6, 9, 13, 18, 26, 39, 78, 117, 234 },
  { 1, 5, 47, 235 },
  { 1, 2, 4, 59, 118, 236 },
  { 1, 3, 79, 237 },
  { 1, 2, 7, 14, 17, 34, 119, 238 },
  { 1, 239 },
  { 1, 2, 3, 4, 5, 6, 8, 10, 12, 15, 16, 20, 24, 30, 40, 48, 60, 80, 120, 240 },
  { 1, 241 },
  { 1, 2, 11, 22, 121, 242 },
  { 1, 3, 9, 27, 81, 243 },
  { 1, 2, 4, 61, 122, 244 },
  { 1, 5, 7, 35, 49, 245 },
  { 1, 2, 3, 6, 41, 82, 123, 246 },
  { 1, 13, 19, 247 },
  { 1, 2, 4, 8, 31, 62, 124, 248 },
  { 1, 3, 83, 249 },
  { 1, 2, 5, 10, 25, 50, 125, 250 },
  { 1, 251 },
  { 1, 2, 3, 4, 6, 7, 9, 12, 14, 18, 21, 28, 36, 42, 63, 84, 126, 252 },
  { 1, 11, 23, 253 },
  { 1, 2, 127, 254 },
  { 1, 3, 5, 15, 17, 51, 85, 255 },
  { 1, 2, 4, 8, 16, 32, 64, 128, 256 },
  { 1, 257 },
  { 1, 2, 3, 6, 43, 86, 129, 258 },
  { 1, 7, 37, 259 },
  { 1, 2, 4, 5, 10, 13, 20, 26, 52, 65, 130, 260 },
  { 1, 3, 9, 29, 87, 261 },
  { 1, 2, 131, 262 },
  { 1, 263 },
  { 1, 2, 3, 4, 6, 8, 11, 12, 22, 24, 33, 44, 66, 88, 132, 264 },
  { 1, 5, 53, 265 },
  { 1, 2, 7, 14, 19, 38, 133, 266 },
  { 1, 3, 89, 267 },
  { 1, 2, 4, 67, 134, 268 },
  { 1, 269 },
  { 1, 2, 3, 5, 6, 9, 10, 15, 18, 27, 30, 45, 54, 90, 135, 270 },
  { 1, 271 },
  { 1, 2, 4, 8, 16, 17, 34, 68, 136, 272 },
  { 1, 3, 7, 13, 21, 39, 91, 273 },
  { 1, 2, 137, 274 },
  { 1, 5, 11, 25, 55, 275 },
  { 1, 2, 3, 4, 6, 12, 23, 46, 69, 92, 138, 276 },
  { 1, 277 },
  { 1, 2, 139, 278 },
  { 1, 3, 9, 31, 93, 279 },
  { 1, 2, 4, 5, 7, 8, 10, 14, 20, 28, 35, 40, 56, 70, 140, 280 },
  { 1, 281 },
  { 1, 2, 3, 6, 47, 94, 141, 282 },
  { 1, 283 },
  { 1, 2, 4, 71, 142, 284 },
  { 1, 3, 5, 15, 19, 57, 95, 285 },
  { 1, 2, 11, 13, 22, 26, 143, 286 },
  { 1, 7, 41, 287 },
  { 1, 2, 3, 4, 6, 8, 9, 12, 16, 18, 24, 32, 36, 48, 72, 96, 144, 288 },
  { 1, 17, 289 },
  { 1, 2, 5, 10, 29, 58, 145, 290 },
  { 1, 3, 97, 291 },
  { 1, 2, 4, 73, 146, 292 },
  { 1, 293 },
  { 1, 2, 3, 6, 7, 14, 21, 42, 49, 98, 147, 294 },
  { 1, 5, 59, 295 },
  { 1, 2, 4, 8, 37, 74, 148, 296 },
  { 1, 3, 9, 11, 27, 33, 99, 297 },
  { 1, 2, 149, 298 },
  { 1, 13, 23, 299 },
  { 1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 25, 30, 50, 60, 75, 100, 150, 300 },
  { 1, 7, 43, 301 },
  { 1, 2, 151, 302 },
  { 1, 3, 101, 303 },
  { 1, 2, 4, 8, 16, 19, 38, 76, 152, 304 },
  { 1, 5, 61, 305 },
  { 1, 2, 3, 6, 9, 17, 18, 34, 51, 102, 153, 306 },
  { 1, 307 },
  { 1, 2, 4, 7, 11, 14, 22, 28, 44, 77, 154, 308 },
  { 1, 3, 103, 309 },
  { 1, 2, 5, 10, 31, 62, 155, 310 },
  { 1, 311 },
  { 1, 2, 3, 4, 6, 8, 12, 13, 24, 26, 39, 52, 78, 104, 156, 312 },
  { 1, 313 },
  { 1, 2, 157, 314 },
  { 1, 3, 5, 7, 9, 15, 21, 35, 45, 63, 105, 315 },
  { 1, 2, 4, 79, 158, 316 },
  { 1, 317 },
  { 1, 2, 3, 6, 53, 106, 159, 318 },
  { 1, 11, 29, 319 },
  { 1, 2, 4, 5, 8, 10, 16, 20, 32, 40, 64, 80, 160, 320 },
  { 1, 3, 107, 321 },
  { 1, 2, 7, 14, 23, 46, 161, 322 },
  { 1, 17, 19, 323 },
  { 1, 2, 3, 4, 6, 9, 12, 18, 27, 36, 54, 81, 108, 162, 324 },
  { 1, 5, 13, 25, 65, 325 },
  { 1, 2, 163, 326 },
  { 1, 3, 109, 327 },
  { 1, 2, 4, 8, 41, 82, 164, 328 },
  { 1, 7, 47, 329 },
  { 1, 2, 3, 5, 6, 10, 11, 15, 22, 30, 33, 55, 66, 110, 165, 330 },
  { 1, 331 },
  { 1, 2, 4, 83, 166, 332 },
  { 1, 3, 9, 37, 111, 333 },
  { 1, 2, 167, 334 },
  { 1, 5, 67, 335 },
  { 1, 2, 3, 4, 6, 7, 8, 12, 14, 16, 21, 24, 28, 42, 48, 56, 84, 112, 168, 336 },
  { 1, 337 },
  { 1, 2, 13, 26, 169, 338 },
  { 1, 3, 113, 339 },
  { 1, 2, 4, 5, 10, 17, 20, 34, 68, 85, 170, 340 },
  { 1, 11, 31, 341 },
  { 1, 2, 3, 6, 9, 18, 19, 38, 57, 114, 171, 342 },
  { 1, 7, 49, 343 },
  { 1, 2, 4, 8, 43, 86, 172, 344 },
  { 1, 3, 5, 15, 23, 69, 115, 345 },
  { 1, 2, 173, 346 },
  { 1, 347 },
  { 1, 2, 3, 4, 6, 12, 29, 58, 87, 116, 174, 348 },
  { 1, 349 },
  { 1, 2, 5, 7, 10, 14, 25, 35, 50, 70, 175, 350 },
  { 1, 3, 9, 13, 27, 39, 117, 351 },
  { 1, 2, 4, 8, 11, 16, 22, 32, 44, 88, 176, 352 },
  { 1, 353 },
  { 1, 2, 3, 6, 59, 118, 177, 354 },
  { 1, 5, 71, 355 },
  { 1, 2, 4, 89, 178, 356 },
  { 1, 3, 7, 17, 21, 51, 119, 357 },
  { 1, 2, 179, 358 },
  { 1, 359 },
  { 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 18, 20, 24, 30, 36, 40, 45, 60, 72, 90, 120, 180, 360 },
  { 1, 19, 361 },
  { 1, 2, 181, 362 },
  { 1, 3, 11, 33, 121, 363 },
  { 1, 2, 4, 7, 13, 14, 26, 28, 52, 91, 182, 364 },
  { 1, 5, 73, 365 },
  { 1, 2, 3, 6, 61, 122, 183, 366 },
  { 1, 367 },
  { 1, 2, 4, 8, 16, 23, 46, 92, 184, 368 },
  { 1, 3, 9, 41, 123, 369 },
  { 1, 2, 5, 10, 37, 74, 185, 370 },
  { 1, 7, 53, 371 },
  { 1, 2, 3, 4, 6, 12, 31, 62, 93, 124, 186, 372 },
  { 1, 373 },
  { 1, 2, 11, 17, 22, 34, 187, 374 },
  { 1, 3, 5, 15, 25, 75, 125, 375 },
  { 1, 2, 4, 8, 47, 94, 188, 376 },
  { 1, 13, 29, 377 },
  { 1, 2, 3, 6, 7, 9, 14, 18, 21, 27, 42, 54, 63, 126, 189, 378 },
  { 1, 379 },
  { 1, 2, 4, 5, 10, 19, 20, 38, 76, 95, 190, 380 },
  { 1, 3, 127, 381 },
  { 1, 2, 191, 382 },
  { 1, 383 },
  { 1, 2, 3, 4, 6, 8, 12, 16, 24, 32, 48, 64, 96, 128, 192, 384 },
  { 1, 5, 7, 11, 35, 55, 77, 385 },
  { 1, 2, 193, 386 },
  { 1, 3, 9, 43, 129, 387 },
  { 1, 2, 4, 97, 194, 388 },
  { 1, 389 },
  { 1, 2, 3, 5, 6, 10, 13, 15, 26, 30, 39, 65, 78, 130, 195, 390 },
  { 1, 17, 23, 391 },
  { 1, 2, 4, 7, 8, 14, 28, 49, 56, 98, 196, 392 },
  { 1, 3, 131, 393 },
  { 1, 2, 197, 394 },
  { 1, 5, 79, 395 },
  { 1, 2, 3, 4, 6, 9, 11, 12, 18, 22, 33, 36, 44, 66, 99, 132, 198, 396 },
  { 1, 397 },
  { 1, 2, 199, 398 },
  { 1, 3, 7, 19, 21, 57, 133, 399 },
  { 1, 2, 4, 5, 8, 10, 16, 20, 25, 40, 50, 80, 100, 200, 400 },
  { 1, 401 },
  { 1, 2, 3, 6, 67, 134, 201, 402 },
  { 1, 13, 31, 403 },
  { 1, 2, 4, 101, 202, 404 },
  { 1, 3, 5, 9, 15, 27, 45, 81, 135, 405 },
  { 1, 2, 7, 14, 29, 58, 203, 406 },
  { 1, 11, 37, 407 },
  { 1, 2, 3, 4, 6, 8, 12, 17, 24, 34, 51, 68, 102, 136, 204, 408 },
  { 1, 409 },
  { 1, 2, 5, 10, 41, 82, 205, 410 },
  { 1, 3, 137, 411 },
  { 1, 2, 4, 103, 206, 412 },
  { 1, 7, 59, 413 },
  { 1, 2, 3, 6, 9, 18, 23, 46, 69, 138, 207, 414 },
  { 1, 5, 83, 415 },
  { 1, 2, 4, 8, 13, 16, 26, 32, 52, 104, 208, 416 },
  { 1, 3, 139, 417 },
  { 1, 2, 11, 19, 22, 38, 209, 418 },
  { 1, 419 },
  { 1, 2, 3, 4, 5, 6, 7, 10, 12, 14, 15, 20, 21, 28, 30, 35, 42, 60, 70, 84, 105, 140, 210, 420 },
  { 1, 421 },
  { 1, 2, 211, 422 },
  { 1, 3, 9, 47, 141, 423 },
  { 1, 2, 4, 8, 53, 106, 212, 424 },
  { 1, 5, 17, 25, 85, 425 },
  { 1, 2, 3, 6, 71, 142, 213, 426 },
  { 1, 7, 61, 427 },
  { 1, 2, 4, 107, 214, 428 },
  { 1, 3, 11, 13, 33, 39, 143, 429 },
  { 1, 2, 5, 10, 43, 86, 215, 430 },
  { 1, 431 },
  { 1, 2, 3, 4, 6, 8, 9, 12, 16, 18, 24, 27, 36, 48, 54, 72, 108, 144, 216, 432 },
  { 1, 433 },
  { 1, 2, 7, 14, 31, 62, 217, 434 },
  { 1, 3, 5, 15, 29, 87, 145, 435 },
  { 1, 2, 4, 109, 218, 436 },
  { 1, 19, 23, 437 },
  { 1, 2, 3, 6, 73, 146, 219, 438 },
  { 1, 439 },
  { 1, 2, 4, 5, 8, 10, 11, 20, 22, 40, 44, 55, 88, 110, 220, 440 },
  { 1, 3, 7, 9, 21, 49, 63, 147, 441 },
  { 1, 2, 13, 17, 26, 34, 221, 442 },
  { 1, 443 },
  { 1, 2, 3, 4, 6, 12, 37, 74, 111, 148, 222, 444 },
  { 1, 5, 89, 445 },
  { 1, 2, 223, 446 },
  { 1, 3, 149, 447 },
  { 1, 2, 4, 7, 8, 14, 16, 28, 32, 56, 64, 112, 224, 448 },
  { 1, 449 },
  { 1, 2, 3, 5, 6, 9, 10, 15, 18, 25, 30, 45, 50, 75, 90, 150, 225, 450 },
  { 1, 11, 41, 451 },
  { 1, 2, 4, 113, 226, 452 },
  { 1, 3, 151, 453 },
  { 1, 2, 227, 454 },
  { 1, 5, 7, 13, 35, 65, 91, 455 },
  { 1, 2, 3, 4, 6, 8, 12, 19, 24, 38, 57, 76, 114, 152, 228, 456 },
  { 1, 457 },
  { 1, 2, 229, 458 },
  { 1, 3, 9, 17, 27, 51, 153, 459 },
  { 1, 2, 4, 5, 10, 20, 23, 46, 92, 115, 230, 460 },
  { 1, 461 },
  { 1, 2, 3, 6, 7, 11, 14, 21, 22, 33, 42, 66, 77, 154, 231, 462 },
  { 1, 463 },
  { 1, 2, 4, 8, 16, 29, 58, 116, 232, 464 },
  { 1, 3, 5, 15, 31, 93, 155, 465 },
  { 1, 2, 233, 466 },
  { 1, 467 },
  { 1, 2, 3, 4, 6, 9, 12, 13, 18, 26, 36, 39, 52, 78, 117, 156, 234, 468 },
  { 1, 7, 67, 469 },
  { 1, 2, 5, 10, 47, 94, 235, 470 },
  { 1, 3, 157, 471 },
  { 1, 2, 4, 8, 59, 118, 236, 472 },
  { 1, 11, 43, 473 },
  { 1, 2, 3, 6, 79, 158, 237, 474 },
  { 1, 5, 19, 25, 95, 475 },
  { 1, 2, 4, 7, 14, 17, 28, 34, 68, 119, 238, 476 },
  { 1, 3, 9, 53, 159, 477 },
  { 1, 2, 239, 478 },
  { 1, 479 },
  { 1, 2, 3, 4, 5, 6, 8, 10, 12, 15, 16, 20, 24, 30, 32, 40, 48, 60, 80, 96, 120, 160, 240, 480 },
  { 1, 13, 37, 481 },
  { 1, 2, 241, 482 },
  { 1, 3, 7, 21, 23, 69, 161, 483 },
  { 1, 2, 4, 11, 22, 44, 121, 242, 484 },
  { 1, 5, 97, 485 },
  { 1, 2, 3, 6, 9, 18, 27, 54, 81, 162, 243, 486 },
  { 1, 487 },
  { 1, 2, 4, 8, 61, 122, 244, 488 },
  { 1, 3, 163, 489 },
  { 1, 2, 5, 7, 10, 14, 35, 49, 70, 98, 245, 490 },
  { 1, 491 },
  { 1, 2, 3, 4, 6, 12, 41, 82, 123, 164, 246, 492 },
  { 1, 17, 29, 493 },
  { 1, 2, 13, 19, 26, 38, 247, 494 },
  { 1, 3, 5, 9, 11, 15, 33, 45, 55, 99, 165, 495 },
  { 1, 2, 4, 8, 16, 31, 62, 124, 248, 496 },
  { 1, 7, 71, 497 },
  { 1, 2, 3, 6, 83, 166, 249, 498 },
  { 1, 499 },
  { 1, 2, 4, 5, 10, 20, 25, 50, 100, 125, 250, 500 },
  { 1, 3, 167, 501 },
  { 1, 2, 251, 502 },
  { 1, 503 },
  { 1, 2, 3, 4, 6, 7, 8, 9, 12, 14, 18, 21, 24, 28, 36, 42, 56, 63, 72, 84, 126, 168, 252, 504 },
  { 1, 5, 101, 505 },
  { 1, 2, 11, 22, 23, 46, 253, 506 },
  { 1, 3, 13, 39, 169, 507 },
  { 1, 2, 4, 127, 254, 508 },
  { 1, 509 },
  { 1, 2, 3, 5, 6, 10, 15, 17, 30, 34, 51, 85, 102, 170, 255, 510 },
  { 1, 7, 73, 511 },
  { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 },
  { 1, 3, 9, 19, 27, 57, 171, 513 },
  { 1, 2, 257, 514 },
  { 1, 5, 103, 515 },
  { 1, 2, 3, 4, 6, 12, 43, 86, 129, 172, 258, 516 },
  { 1, 11, 47, 517 },
  { 1, 2, 7, 14, 37, 74, 259, 518 },
  { 1, 3, 173, 519 },
  { 1, 2, 4, 5, 8, 10, 13, 20, 26, 40, 52, 65, 104, 130, 260, 520 },
  { 1, 521 },
  { 1, 2, 3, 6, 9, 18, 29, 58, 87, 174, 261, 522 },
  { 1, 523 },
  { 1, 2, 4, 131, 262, 524 },
  { 1, 3, 5, 7, 15, 21, 25, 35, 75, 105, 175, 525 },
  { 1, 2, 263, 526 },
  { 1, 17, 31, 527 },
  { 1, 2, 3, 4, 6, 8, 11, 12, 16, 22, 24, 33, 44, 48, 66, 88, 132, 176, 264, 528 },
  { 1, 23, 529 },
  { 1, 2, 5, 10, 53, 106, 265, 530 },
  { 1, 3, 9, 59, 177, 531 },
  { 1, 2, 4, 7, 14, 19, 28, 38, 76, 133, 266, 532 },
  { 1, 13, 41, 533 },
  { 1, 2, 3, 6, 89, 178, 267, 534 },
  { 1, 5, 107, 535 },
  { 1, 2, 4, 8, 67, 134, 268, 536 },
  { 1, 3, 179, 537 },
  { 1, 2, 269, 538 },
  { 1, 7, 11, 49, 77, 539 },
  { 1, 2, 3, 4, 5, 6, 9, 10, 12, 15, 18, 20, 27, 30, 36, 45, 54, 60, 90, 108, 135, 180, 270, 540 },
  { 1, 541 },
  { 1, 2, 271, 542 },
  { 1, 3, 181, 543 },
  { 1, 2, 4, 8, 16, 17, 32, 34, 68, 136, 272, 544 },
  { 1, 5, 109, 545 },
  { 1, 2, 3, 6, 7, 13, 14, 21, 26, 39, 42, 78, 91, 182, 273, 546 },
  { 1, 547 },
  { 1, 2, 4, 137, 274, 548 },
  { 1, 3, 9, 61, 183, 549 },
  { 1, 2, 5, 10, 11, 22, 25, 50, 55, 110, 275, 550 },
  { 1, 19, 29, 551 },
  { 1, 2, 3, 4, 6, 8, 12, 23, 24, 46, 69, 92, 138, 184, 276, 552 },
  { 1, 7, 79, 553 },
  { 1, 2, 277, 554 },
  { 1, 3, 5, 15, 37, 111, 185, 555 },
  { 1, 2, 4, 139, 278, 556 },
  { 1, 557 },
  { 1, 2, 3, 6, 9, 18, 31, 62, 93, 186, 279, 558 },
  { 1, 13, 43, 559 },
  { 1, 2, 4, 5, 7, 8, 10, 14, 16, 20, 28, 35, 40, 56, 70, 80, 112, 140, 280, 560 },
  { 1, 3, 11, 17, 33, 51, 187, 561 },
  { 1, 2, 281, 562 },
  { 1, 563 },
  { 1, 2, 3, 4, 6, 12, 47, 94, 141, 188, 282, 564 },
  { 1, 5, 113, 565 },
  { 1, 2, 283, 566 },
  { 1, 3, 7, 9, 21, 27, 63, 81, 189, 567 },
  { 1, 2, 4, 8, 71, 142, 284, 568 },
  { 1, 569 },
  { 1, 2, 3, 5, 6, 10, 15, 19, 30, 38, 57, 95, 114, 190, 285, 570 },
  { 1, 571 },
  { 1, 2, 4, 11, 13, 22, 26, 44, 52, 143, 286, 572 },
  { 1, 3, 191, 573 },
  { 1, 2, 7, 14, 41, 82, 287, 574 },
  { 1, 5, 23, 25, 115, 575 },
  { 1, 2, 3, 4, 6, 8, 9, 12, 16, 18, 24, 32, 36, 48, 64, 72, 96, 144, 192, 288, 576 },
  { 1, 577 },
  { 1, 2, 17, 34, 289, 578 },
  { 1, 3, 193, 579 },
  { 1, 2, 4, 5, 10, 20, 29, 58, 116, 145, 290, 580 },
  { 1, 7, 83, 581 },
  { 1, 2, 3, 6, 97, 194, 291, 582 },
  { 1, 11, 53, 583 },
  { 1, 2, 4, 8, 73, 146, 292, 584 },
  { 1, 3, 5, 9, 13, 15, 39, 45, 65, 117, 195, 585 },
  { 1, 2, 293, 586 },
  { 1, 587 },
  { 1, 2, 3, 4, 6, 7, 12, 14, 21, 28, 42, 49, 84, 98, 147, 196, 294, 588 },
  { 1, 19, 31, 589 },
  { 1, 2, 5, 10, 59, 118, 295, 590 },
  { 1, 3, 197, 591 },
  { 1, 2, 4, 8, 16, 37, 74, 148, 296, 592 },
  { 1, 593 },
  { 1, 2, 3, 6, 9, 11, 18, 22, 27, 33, 54, 66, 99, 198, 297, 594 },
  { 1, 5, 7, 17, 35, 85, 119, 595 },
  { 1, 2, 4, 149, 298, 596 },
  { 1, 3, 199, 597 },
  { 1, 2, 13, 23, 26, 46, 299, 598 },
  { 1, 599 },
  { 1, 2, 3, 4, 5, 6, 8, 10, 12, 15, 20, 24, 25, 30, 40, 50, 60, 75, 100, 120, 150, 200, 300, 600 },
  { 1, 601 },
  { 1, 2, 7, 14, 43, 86, 301, 602 },
  { 1, 3, 9, 67, 201, 603 },
  { 1, 2, 4, 151, 302, 604 },
  { 1, 5, 11, 55, 121, 605 },
  { 1, 2, 3, 6, 101, 202, 303, 606 },
  { 1, 607 },
  { 1, 2, 4, 8, 16, 19, 32, 38, 76, 152, 304, 608 },
  { 1, 3, 7, 21, 29, 87, 203, 609 },
  { 1, 2, 5, 10, 61, 122, 305, 610 },
  { 1, 13, 47, 611 },
  { 1, 2, 3, 4, 6, 9, 12, 17, 18, 34, 36, 51, 68, 102, 153, 204, 306, 612 },
  { 1, 613 },
  { 1, 2, 307, 614 },
  { 1, 3, 5, 15, 41, 123, 205, 615 },
  { 1, 2, 4, 7, 8, 11, 14, 22, 28, 44, 56, 77, 88, 154, 308, 616 },
  { 1, 617 },
  { 1, 2, 3, 6, 103, 206, 309, 618 },
  { 1, 619 },
  { 1, 2, 4, 5, 10, 20, 31, 62, 124, 155, 310, 620 },
  { 1, 3, 9, 23, 27, 69, 207, 621 },
  { 1, 2, 311, 622 },
  { 1, 7, 89, 623 },
  { 1, 2, 3, 4, 6, 8, 12, 13, 16, 24, 26, 39, 48, 52, 78, 104, 156, 208, 312, 624 },
  { 1, 5, 25, 125, 625 },
  { 1, 2, 313, 626 },
  { 1, 3, 11, 19, 33, 57, 209, 627 },
  { 1, 2, 4, 157, 314, 628 },
  { 1, 17, 37, 629 },
  { 1, 2, 3, 5, 6, 7, 9, 10, 14, 15, 18, 21, 30, 35, 42, 45, 63, 70, 90, 105, 126, 210, 315, 630 },
  { 1, 631 },
  { 1, 2, 4, 8, 79, 158, 316, 632 },
  { 1, 3, 211, 633 },
  { 1, 2, 317, 634 },
  { 1, 5, 127, 635 },
  { 1, 2, 3, 4, 6, 12, 53, 106, 159, 212, 318, 636 },
  { 1, 7, 13, 49, 91, 637 },
  { 1, 2, 11, 22, 29, 58, 319, 638 },
  { 1, 3, 9, 71, 213, 639 },
  { 1, 2, 4, 5, 8, 10, 16, 20, 32, 40, 64, 80, 128, 160, 320, 640 },
  { 1, 641 },
  { 1, 2, 3, 6, 107, 214, 321, 642 },
  { 1, 643 },
  { 1, 2, 4, 7, 14, 23, 28, 46, 92, 161, 322, 644 },
  { 1, 3, 5, 15, 43, 129, 215, 645 },
  { 1, 2, 17, 19, 34, 38, 323, 646 },
  { 1, 647 },
  { 1, 2, 3, 4, 6, 8, 9, 12, 18, 24, 27, 36, 54, 72, 81, 108, 162, 216, 324, 648 },
  { 1, 11, 59, 649 },
  { 1, 2, 5, 10, 13, 25, 26, 50, 65, 130, 325, 650 },
  { 1, 3, 7, 21, 31, 93, 217, 651 },
  { 1, 2, 4, 163, 326, 652 },
  { 1, 653 },
  { 1, 2, 3, 6, 109, 218, 327, 654 },
  { 1, 5, 131, 655 },
  { 1, 2, 4, 8, 16, 41, 82, 164, 328, 656 },
  { 1, 3, 9, 73, 219, 657 },
  { 1, 2, 7, 14, 47, 94, 329, 658 },
  { 1, 659 },
  { 1, 2, 3, 4, 5, 6, 10, 11, 12, 15, 20, 22, 30, 33, 44, 55, 60, 66, 110, 132, 165, 220, 330, 660 },
  { 1, 661 },
  { 1, 2, 331, 662 },
  { 1, 3, 13, 17, 39, 51, 221, 663 },
  { 1, 2, 4, 8, 83, 166, 332, 664 },
  { 1, 5, 7, 19, 35, 95, 133, 665 },
  { 1, 2, 3, 6, 9, 18, 37, 74, 111, 222, 333, 666 },
  { 1, 23, 29, 667 },
  { 1, 2, 4, 167, 334, 668 },
  { 1, 3, 223, 669 },
  { 1, 2, 5, 10, 67, 134, 335, 670 },
  { 1, 11, 61, 671 },
  { 1, 2, 3, 4, 6, 7, 8, 12, 14, 16, 21, 24, 28, 32, 42, 48, 56, 84, 96, 112, 168, 224, 336, 672 },
  { 1, 673 },
  { 1, 2, 337, 674 },
  { 1, 3, 5, 9, 15, 25, 27, 45, 75, 135, 225, 675 },
  { 1, 2, 4, 13, 26, 52, 169, 338, 676 },
  { 1, 677 },
  { 1, 2, 3, 6, 113, 226, 339, 678 },
  { 1, 7, 97, 679 },
  { 1, 2, 4, 5, 8, 10, 17, 20, 34, 40, 68, 85, 136, 170, 340, 680 },
  { 1, 3, 227, 681 },
  { 1, 2, 11, 22, 31, 62, 341, 682 },
  { 1, 683 },
  { 1, 2, 3, 4, 6, 9, 12, 18, 19, 36, 38, 57, 76, 114, 171, 228, 342, 684 },
  { 1, 5, 137, 685 },
  { 1, 2, 7, 14, 49, 98, 343, 686 },
  { 1, 3, 229, 687 },
  { 1, 2, 4, 8, 16, 43, 86, 172, 344, 688 },
  { 1, 13, 53, 689 },
  { 1, 2, 3, 5, 6, 10, 15, 23, 30, 46, 69, 115, 138, 230, 345, 690 },
  { 1, 691 },
  { 1, 2, 4, 173, 346, 692 },
  { 1, 3, 7, 9, 11, 21, 33, 63, 77, 99, 231, 693 },
  { 1, 2, 347, 694 },
  { 1, 5, 139, 695 },
  { 1, 2, 3, 4, 6, 8, 12, 24, 29, 58, 87, 116, 174, 232, 348, 696 },
  { 1, 17, 41, 697 },
  { 1, 2, 349, 698 },
  { 1, 3, 233, 699 },
  { 1, 2, 4, 5, 7, 10, 14, 20, 25, 28, 35, 50, 70, 100, 140, 175, 350, 700 },
  { 1, 701 },
  { 1, 2, 3, 6, 9, 13, 18, 26, 27, 39, 54, 78, 117, 234, 351, 702 },
  { 1, 19, 37, 703 },
  { 1, 2, 4, 8, 11, 16, 22, 32, 44, 64, 88, 176, 352, 704 },
  { 1, 3, 5, 15, 47, 141, 235, 705 },
  { 1, 2, 353, 706 },
  { 1, 7, 101, 707 },
  { 1, 2, 3, 4, 6, 12, 59, 118, 177, 236, 354, 708 },
  { 1, 709 },
  { 1, 2, 5, 10, 71, 142, 355, 710 },
  { 1, 3, 9, 79, 237, 711 },
  { 1, 2, 4, 8, 89, 178, 356, 712 },
  { 1, 23, 31, 713 },
  { 1, 2, 3, 6, 7, 14, 17, 21, 34, 42, 51, 102, 119, 238, 357, 714 },
  { 1, 5, 11, 13, 55, 65, 143, 715 },
  { 1, 2, 4, 179, 358, 716 },
  { 1, 3, 239, 717 },
  { 1, 2, 359, 718 },
  { 1, 719 },
  { 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24, 30, 36, 40, 45, 48, 60, 72, 80, 90, 120, 144, 180, 240, 360, 720 },
  { 1, 7, 103, 721 },
  { 1, 2, 19, 38, 361, 722 },
  { 1, 3, 241, 723 },
  { 1, 2, 4, 181, 362, 724 },
  { 1, 5, 25, 29, 145, 725 },
  { 1, 2, 3, 6, 11, 22, 33, 66, 121, 242, 363, 726 },
  { 1, 727 },
  { 1, 2, 4, 7, 8, 13, 14, 26, 28, 52, 56, 91, 104, 182, 364, 728 },
  { 1, 3, 9, 27, 81, 243, 729 },
  { 1, 2, 5, 10, 73, 146, 365, 730 },
  { 1, 17, 43, 731 },
  { 1, 2, 3, 4, 6, 12, 61, 122, 183, 244, 366, 732 },
  { 1, 733 },
  { 1, 2, 367, 734 },
  { 1, 3, 5, 7, 15, 21, 35, 49, 105, 147, 245, 735 },
  { 1, 2, 4, 8, 16, 23, 32, 46, 92, 184, 368, 736 },
  { 1, 11, 67, 737 },
  { 1, 2, 3, 6, 9, 18, 41, 82, 123, 246, 369, 738 },
  { 1, 739 },
  { 1, 2, 4, 5, 10, 20, 37, 74, 148, 185, 370, 740 },
  { 1, 3, 13, 19, 39, 57, 247, 741 },
  { 1, 2, 7, 14, 53, 106, 371, 742 },
  { 1, 743 },
  { 1, 2, 3, 4, 6, 8, 12, 24, 31, 62, 93, 124, 186, 248, 372, 744 },
  { 1, 5, 149, 745 },
  { 1, 2, 373, 746 },
  { 1, 3, 9, 83, 249, 747 },
  { 1, 2, 4, 11, 17, 22, 34, 44, 68, 187, 374, 748 },
  { 1, 7, 107, 749 },
  { 1, 2, 3, 5, 6, 10, 15, 25, 30, 50, 75, 125, 150, 250, 375, 750 },
  { 1, 751 },
  { 1, 2, 4, 8, 16, 47, 94, 188, 376, 752 },
  { 1, 3, 251, 753 },
  { 1, 2, 13, 26, 29, 58, 377, 754 },
  { 1, 5, 151, 755 },
  { 1, 2, 3, 4, 6, 7, 9, 12, 14, 18, 21, 27, 28, 36, 42, 54, 63, 84, 108, 126, 189, 252, 378, 756 },
  { 1, 757 },
  { 1, 2, 379, 758 },
  { 1, 3, 11, 23, 33, 69, 253, 759 },
  { 1, 2, 4, 5, 8, 10, 19, 20, 38, 40, 76, 95, 152, 190, 380, 760 },
  { 1, 761 },
  { 1, 2, 3, 6, 127, 254, 381, 762 },
  { 1, 7, 109, 763 },
  { 1, 2, 4, 191, 382, 764 },
  { 1, 3, 5, 9, 15, 17, 45, 51, 85, 153, 255, 765 },
  { 1, 2, 383, 766 },
  { 1, 13, 59, 767 },
  { 1, 2, 3, 4, 6, 8, 12, 16, 24, 32, 48, 64, 96, 128, 192, 256, 384, 768 },
  { 1, 769 },
  { 1, 2, 5, 7, 10, 11, 14, 22, 35, 55, 70, 77, 110, 154, 385, 770 },
  { 1, 3, 257, 771 },
  { 1, 2, 4, 193, 386, 772 },
  { 1, 773 },
  { 1, 2, 3, 6, 9, 18, 43, 86, 129, 258, 387, 774 },
  { 1, 5, 25, 31, 155, 775 },
  { 1, 2, 4, 8, 97, 194, 388, 776 },
  { 1, 3, 7, 21, 37, 111, 259, 777 },
  { 1, 2, 389, 778 },
  { 1, 19, 41, 779 },
  { 1, 2, 3, 4, 5, 6, 10, 12, 13, 15, 20, 26, 30, 39, 52, 60, 65, 78, 130, 156, 195, 260, 390, 780 },
  { 1, 11, 71, 781 },
  { 1, 2, 17, 23, 34, 46, 391, 782 },
  { 1, 3, 9, 27, 29, 87, 261, 783 },
  { 1, 2, 4, 7, 8, 14, 16, 28, 49, 56, 98, 112, 196, 392, 784 },
  { 1, 5, 157, 785 },
  { 1, 2, 3, 6, 131, 262, 393, 786 },
  { 1, 787 },
  { 1, 2, 4, 197, 394, 788 },
  { 1, 3, 263, 789 },
  { 1, 2, 5, 10, 79, 158, 395, 790 },
  { 1, 7, 113, 791 },
  { 1, 2, 3, 4, 6, 8, 9, 11, 12, 18, 22, 24, 33, 36, 44, 66, 72, 88, 99, 132, 198, 264, 396, 792 },
  { 1, 13, 61, 793 },
  { 1, 2, 397, 794 },
  { 1, 3, 5, 15, 53, 159, 265, 795 },
  { 1, 2, 4, 199, 398, 796 },
  { 1, 797 },
  { 1, 2, 3, 6, 7, 14, 19, 21, 38, 42, 57, 114, 133, 266, 399, 798 },
  { 1, 17, 47, 799 },
  { 1, 2, 4, 5, 8, 10, 16, 20, 25, 32, 40, 50, 80, 100, 160, 200, 400, 800 },
  { 1, 3, 9, 89, 267, 801 },
  { 1, 2, 401, 802 },
  { 1, 11, 73, 803 },
  { 1, 2, 3, 4, 6, 12, 67, 134, 201, 268, 402, 804 },
  { 1, 5, 7, 23, 35, 115, 161, 805 },
  { 1, 2, 13, 26, 31, 62, 403, 806 },
  { 1, 3, 269, 807 },
  { 1, 2, 4, 8, 101, 202, 404, 808 },
  { 1, 809 },
  { 1, 2, 3, 5, 6, 9, 10, 15, 18, 27, 30, 45, 54, 81, 90, 135, 162, 270, 405, 810 },
  { 1, 811 },
  { 1, 2, 4, 7, 14, 28, 29, 58, 116, 203, 406, 812 },
  { 1, 3, 271, 813 },
  { 1, 2, 11, 22, 37, 74, 407, 814 },
  { 1, 5, 163, 815 },
  { 1, 2, 3, 4, 6, 8, 12, 16, 17, 24, 34, 48, 51, 68, 102, 136, 204, 272, 408, 816 },
  { 1, 19, 43, 817 },
  { 1, 2, 409, 818 },
  { 1, 3, 7, 9, 13, 21, 39, 63, 91, 117, 273, 819 },
  { 1, 2, 4, 5, 10, 20, 41, 82, 164, 205, 410, 820 },
  { 1, 821 },
  { 1, 2, 3, 6, 137, 274, 411, 822 },
  { 1, 823 },
  { 1, 2, 4, 8, 103, 206, 412, 824 },
  { 1, 3, 5, 11, 15, 25, 33, 55, 75, 165, 275, 825 },
  { 1, 2, 7, 14, 59, 118, 413, 826 },
  { 1, 827 },
  { 1, 2, 3, 4, 6, 9, 12, 18, 23, 36, 46, 69, 92, 138, 207, 276, 414, 828 },
  { 1, 829 },
  { 1, 2, 5, 10, 83, 166, 415, 830 },
  { 1, 3, 277, 831 },
  { 1, 2, 4, 8, 13, 16, 26, 32, 52, 64, 104, 208, 416, 832 },
  { 1, 7, 17, 49, 119, 833 },
  { 1, 2, 3, 6, 139, 278, 417, 834 },
  { 1, 5, 167, 835 },
  { 1, 2, 4, 11, 19, 22, 38, 44, 76, 209, 418, 836 },
  { 1, 3, 9, 27, 31, 93, 279, 837 },
  { 1, 2, 419, 838 },
  { 1, 839 },
  { 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 14, 15, 20, 21, 24, 28, 30, 35, 40, 42, 56, 60, 70, 84, 105, 120, 140, 168, 210, 280, 420, 840 },
  { 1, 29, 841 },
  { 1, 2, 421, 842 },
  { 1, 3, 281, 843 },
  { 1, 2, 4, 211, 422, 844 },
  { 1, 5, 13, 65, 169, 845 },
  { 1, 2, 3, 6, 9, 18, 47, 94, 141, 282, 423, 846 },
  { 1, 7, 11, 77, 121, 847 },
  { 1, 2, 4, 8, 16, 53, 106, 212, 424, 848 },
  { 1, 3, 283, 849 },
  { 1, 2, 5, 10, 17, 25, 34, 50, 85, 170, 425, 850 },
  { 1, 23, 37, 851 },
  { 1, 2, 3, 4, 6, 12, 71, 142, 213, 284, 426, 852 },
  { 1, 853 },
  { 1, 2, 7, 14, 61, 122, 427, 854 },
  { 1, 3, 5, 9, 15, 19, 45, 57, 95, 171, 285, 855 },
  { 1, 2, 4, 8, 107, 214, 428, 856 },
  { 1, 857 },
  { 1, 2, 3, 6, 11, 13, 22, 26, 33, 39, 66, 78, 143, 286, 429, 858 },
  { 1, 859 },
  { 1, 2, 4, 5, 10, 20, 43, 86, 172, 215, 430, 860 },
  { 1, 3, 7, 21, 41, 123, 287, 861 },
  { 1, 2, 431, 862 },
  { 1, 863 },
  { 1, 2, 3, 4, 6, 8, 9, 12, 16, 18, 24, 27, 32, 36, 48, 54, 72, 96, 108, 144, 216, 288, 432, 864 },
  { 1, 5, 173, 865 },
  { 1, 2, 433, 866 },
  { 1, 3, 17, 51, 289, 867 },
  { 1, 2, 4, 7, 14, 28, 31, 62, 124, 217, 434, 868 },
  { 1, 11, 79, 869 },
  { 1, 2, 3, 5, 6, 10, 15, 29, 30, 58, 87, 145, 174, 290, 435, 870 },
  { 1, 13, 67, 871 },
  { 1, 2, 4, 8, 109, 218, 436, 872 },
  { 1, 3, 9, 97, 291, 873 },
  { 1, 2, 19, 23, 38, 46, 437, 874 },
  { 1, 5, 7, 25, 35, 125, 175, 875 },
  { 1, 2, 3, 4, 6, 12, 73, 146, 219, 292, 438, 876 },
  { 1, 877 },
  { 1, 2, 439, 878 },
  { 1, 3, 293, 879 },
  { 1, 2, 4, 5, 8, 10, 11, 16, 20, 22, 40, 44, 55, 80, 88, 110, 176, 220, 440, 880 },
  { 1, 881 },
  { 1, 2, 3, 6, 7, 9, 14, 18, 21, 42, 49, 63, 98, 126, 147, 294, 441, 882 },
  { 1, 883 },
  { 1, 2, 4, 13, 17, 26, 34, 52, 68, 221, 442, 884 },
  { 1, 3, 5, 15, 59, 177, 295, 885 },
  { 1, 2, 443, 886 },
  { 1, 887 },
  { 1, 2, 3, 4, 6, 8, 12, 24, 37, 74, 111, 148, 222, 296, 444, 888 },
  { 1, 7, 127, 889 },
  { 1, 2, 5, 10, 89, 178, 445, 890 },
  { 1, 3, 9, 11, 27, 33, 81, 99, 297, 891 },
  { 1, 2, 4, 223, 446, 892 },
  { 1, 19, 47, 893 },
  { 1, 2, 3, 6, 149, 298, 447, 894 },
  { 1, 5, 179, 895 },
  { 1, 2, 4, 7, 8, 14, 16, 28, 32, 56, 64, 112, 128, 224, 448, 896 },
  { 1, 3, 13, 23, 39, 69, 299, 897 },
  { 1, 2, 449, 898 },
  { 1, 29, 31, 899 },
  { 1, 2, 3, 4, 5, 6, 9, 10, 12, 15, 18, 20, 25, 30, 36, 45, 50, 60, 75, 90, 100, 150, 180, 225, 300, 450, 900 },
  { 1, 17, 53, 901 },
  { 1, 2, 11, 22, 41, 82, 451, 902 },
  { 1, 3, 7, 21, 43, 129, 301, 903 },
  { 1, 2, 4, 8, 113, 226, 452, 904 },
  { 1, 5, 181, 905 },
  { 1, 2, 3, 6, 151, 302, 453, 906 },
  { 1, 907 },
  { 1, 2, 4, 227, 454, 908 },
  { 1, 3, 9, 101, 303, 909 },
  { 1, 2, 5, 7, 10, 13, 14, 26, 35, 65, 70, 91, 130, 182, 455, 910 },
  { 1, 911 },
  { 1, 2, 3, 4, 6, 8, 12, 16, 19, 24, 38, 48, 57, 76, 114, 152, 228, 304, 456, 912 },
  { 1, 11, 83, 913 },
  { 1, 2, 457, 914 },
  { 1, 3, 5, 15, 61, 183, 305, 915 },
  { 1, 2, 4, 229, 458, 916 },
  { 1, 7, 131, 917 },
  { 1, 2, 3, 6, 9, 17, 18, 27, 34, 51, 54, 102, 153, 306, 459, 918 },
  { 1, 919 },
  { 1, 2, 4, 5, 8, 10, 20, 23, 40, 46, 92, 115, 184, 230, 460, 920 },
  { 1, 3, 307, 921 },
  { 1, 2, 461, 922 },
  { 1, 13, 71, 923 },
  { 1, 2, 3, 4, 6, 7, 11, 12, 14, 21, 22, 28, 33, 42, 44, 66, 77, 84, 132, 154, 231, 308, 462, 924 },
  { 1, 5, 25, 37, 185, 925 },
  { 1, 2, 463, 926 },
  { 1, 3, 9, 103, 309, 927 },
  { 1, 2, 4, 8, 16, 29, 32, 58, 116, 232, 464, 928 },
  { 1, 929 },
  { 1, 2, 3, 5, 6, 10, 15, 30, 31, 62, 93, 155, 186, 310, 465, 930 },
  { 1, 7, 19, 49, 133, 931 },
  { 1, 2, 4, 233, 466, 932 },
  { 1, 3, 311, 933 },
  { 1, 2, 467, 934 },
  { 1, 5, 11, 17, 55, 85, 187, 935 },
  { 1, 2, 3, 4, 6, 8, 9, 12, 13, 18, 24, 26, 36, 39, 52, 72, 78, 104, 117, 156, 234, 312, 468, 936 },
  { 1, 937 },
  { 1, 2, 7, 14, 67, 134, 469, 938 },
  { 1, 3, 313, 939 },
  { 1, 2, 4, 5, 10, 20, 47, 94, 188, 235, 470, 940 },
  { 1, 941 },
  { 1, 2, 3, 6, 157, 314, 471, 942 },
  { 1, 23, 41, 943 },
  { 1, 2, 4, 8, 16, 59, 118, 236, 472, 944 },
  { 1, 3, 5, 7, 9, 15, 21, 27, 35, 45, 63, 105, 135, 189, 315, 945 },
  { 1, 2, 11, 22, 43, 86, 473, 946 },
  { 1, 947 },
  { 1, 2, 3, 4, 6, 12, 79, 158, 237, 316, 474, 948 },
  { 1, 13, 73, 949 },
  { 1, 2, 5, 10, 19, 25, 38, 50, 95, 190, 475, 950 },
  { 1, 3, 317, 951 },
  { 1, 2, 4, 7, 8, 14, 17, 28, 34, 56, 68, 119, 136, 238, 476, 952 },
  { 1, 953 },
  { 1, 2, 3, 6, 9, 18, 53, 106, 159, 318, 477, 954 },
  { 1, 5, 191, 955 },
  { 1, 2, 4, 239, 478, 956 },
  { 1, 3, 11, 29, 33, 87, 319, 957 },
  { 1, 2, 479, 958 },
  { 1, 7, 137, 959 },
  { 1, 2, 3, 4, 5, 6, 8, 10, 12, 15, 16, 20, 24, 30, 32, 40, 48, 60, 64, 80, 96, 120, 160, 192, 240, 320, 480, 960 },
  { 1, 31, 961 },
  { 1, 2, 13, 26, 37, 74, 481, 962 },
  { 1, 3, 9, 107, 321, 963 },
  { 1, 2, 4, 241, 482, 964 },
  { 1, 5, 193, 965 },
  { 1, 2, 3, 6, 7, 14, 21, 23, 42, 46, 69, 138, 161, 322, 483, 966 },
  { 1, 967 },
  { 1, 2, 4, 8, 11, 22, 44, 88, 121, 242, 484, 968 },
  { 1, 3, 17, 19, 51, 57, 323, 969 },
  { 1, 2, 5, 10, 97, 194, 485, 970 },
  { 1, 971 },
  { 1, 2, 3, 4, 6, 9, 12, 18, 27, 36, 54, 81, 108, 162, 243, 324, 486, 972 },
  { 1, 7, 139, 973 },
  { 1, 2, 487, 974 },
  { 1, 3, 5, 13, 15, 25, 39, 65, 75, 195, 325, 975 },
  { 1, 2, 4, 8, 16, 61, 122, 244, 488, 976 },
  { 1, 977 },
  { 1, 2, 3, 6, 163, 326, 489, 978 },
  { 1, 11, 89, 979 },
  { 1, 2, 4, 5, 7, 10, 14, 20, 28, 35, 49, 70, 98, 140, 196, 245, 490, 980 },
  { 1, 3, 9, 109, 327, 981 },
  { 1, 2, 491, 982 },
  { 1, 983 },
  { 1, 2, 3, 4, 6, 8, 12, 24, 41, 82, 123, 164, 246, 328, 492, 984 },
  { 1, 5, 197, 985 },
  { 1, 2, 17, 29, 34, 58, 493, 986 },
  { 1, 3, 7, 21, 47, 141, 329, 987 },
  { 1, 2, 4, 13, 19, 26, 38, 52, 76, 247, 494, 988 },
  { 1, 23, 43, 989 },
  { 1, 2, 3, 5, 6, 9, 10, 11, 15, 18, 22, 30, 33, 45, 55, 66, 90, 99, 110, 165, 198, 330, 495, 990 },
  { 1, 991 },
  { 1, 2, 4, 8, 16, 31, 32, 62, 124, 248, 496, 992 },
  { 1, 3, 331, 993 },
  { 1, 2, 7, 14, 71, 142, 497, 994 },
  { 1, 5, 199, 995 },
  { 1, 2, 3, 4, 6, 12, 83, 166, 249, 332, 498, 996 },
  { 1, 997 },
  { 1, 2, 499, 998 },
  { 1, 3, 9, 27, 37, 111, 333, 999 },
  { 1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 125, 200, 250, 500, 1000 }
};

long long max_consequtive_subsum_from_raw(const long long raw[100], const int length_of_raw, const int length_of_subsequence) {
  long long max_sum = 0;
  for (int i = 0; i < length_of_subsequence; ++i) {
    max_sum += raw[i];
  }
  long long current_sum = max_sum;
  for (int i = length_of_subsequence; i < length_of_raw; ++i) {
    current_sum = current_sum + raw[i] - raw[i - length_of_subsequence];
    max_sum = max(max_sum, current_sum);
  }
  return max_sum;
}

void put_max_fix_sized_submatrix_sum_to_value(const long long matrix[1000][100], const int M, const int N, const int m, const int n, long long &max_sum) {
  long long sum_of_m_columns[100] = {};
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < N; ++j) {  
      sum_of_m_columns[j] += matrix[i][j];
    }
  }

  max_sum = max(max_sum, max_consequtive_subsum_from_raw(sum_of_m_columns, N, n));

  for (int i = 0; i < M - m; ++i) {
    for (int j = 0; j < N; ++j) {
      sum_of_m_columns[j] += matrix[i+m][j] - matrix[i][j];
    }

    max_sum = max(max_sum, max_consequtive_subsum_from_raw(sum_of_m_columns, N, n));
  }
  
  return;
}

int main() {
    int K, M, N;
    long long D[1000][100];

    cin >> K >> M >> N;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> D[i][j];
        }
    }

    long long max_sum = D[0][0];

    for (int k = 1; k <= K; ++k) {
        for (int i = 0; i < number_of_dividers[k]; ++i) {
            put_max_fix_sized_submatrix_sum_to_value(D, M, N, dividers_map[k][i], k / dividers_map[k][i], max_sum);
        }
    }

    cout << max_sum;

    return 0;
}
