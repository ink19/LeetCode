#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    std::map<string, int> name_to_int;
    std::map<int, std::set<string>> int_to_map;
    
    std::map<int, int> int_name_freq;
    std::vector<std::string> result;
    int name_int_loop = 1;
    int unpack(vector<string>& synonyms) {
        const int synonyms_len = synonyms.size();
        char name1[1024], name2[1024];
        
        for (int loop_i = 0; loop_i < synonyms_len; ++loop_i) {
            std::sscanf(synonyms[loop_i].data(), "(%[^,],%[^)])", name1, name2);
            string name_s1{name1};
            string name_s2{name2};
            int name_int1 = name_to_int[name_s1];
            int name_int2 = name_to_int[name_s2];
            if (name_int1 == 0 && name_int2 == 0) {
                name_to_int[name_s1] = name_int_loop;
                name_to_int[name_s2] = name_int_loop;
                int_to_map[name_int_loop] = {name_s1, name_s2};
                name_int_loop++;
            } else if (name_int1 != 0 && name_int2 != 0) {
                if (name_int2 == name_int1) continue;
                auto int_to_map1 = int_to_map[name_int1];
                auto int_to_map2 = int_to_map[name_int2];
                for (auto name_iter2 : int_to_map2) {
                    int_to_map1.insert(name_iter2);
                    name_to_int[name_iter2] = name_int1;
                }
                int_to_map[name_int1] = int_to_map1;
                int_to_map.erase(name_int2);
            } else if (name_int1 != 0) {
                auto int_to_map1 = int_to_map[name_int1];
                int_to_map1.insert(name_s2);
                int_to_map[name_int1] = int_to_map1;
                name_to_int[name_s2] = name_int1;
            } else {
                auto int_to_map2 = int_to_map[name_int2];
                int_to_map2.insert(name_s1);
                int_to_map[name_int2] = int_to_map2;
                name_to_int[name_s1] = name_int2;
                
            }
        }
        return 0;
    }

    int unpack_names(vector<string> &names) {
        const int names_len = names.size();
        char name[1024];
        int freq;
        for (int loop_i = 0; loop_i < names_len; ++loop_i) {
            std::sscanf(names[loop_i].data(), "%[^(](%d)", name, &freq);
            std::string name_s = name;
            int name_int = name_to_int[name_s];
            if (name_int == 0) {
                name_to_int[name_s] = name_int_loop;
                int_to_map[name_int_loop] = {name_s};
                name_int = name_int_loop;
                name_int_loop++;
            }
            int_name_freq[name_int] = int_name_freq[name_int] + freq;
        }
        return 0;
    }

    int gen_result() {
        char result_iter[1024];
        for (auto int_name_iter : int_name_freq) {
            std::string name = *int_to_map[int_name_iter.first].begin();
            std::sprintf(result_iter, "%s(%d)", name.data(), int_name_iter.second);
            result.push_back(result_iter);
        }
        return 0;
    }

    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        unpack(synonyms);
        unpack_names(names);
        gen_result();
        return result;
    }
};


int main() {
    vector<string> names = {"Pwsuo(71)","Prf(48)","Rgbu(49)","Zvzm(31)","Xxcl(25)","Bbcpth(42)","Padz(70)","Jmqqsj(19)","Uwy(26)","Jylbla(65)","Xioal(11)","Npbu(62)","Jpftyg(96)","Tal(46)","Hnc(100)","Yldu(85)","Alqw(45)","Wbcxi(34)","Kxjw(36)","Clplqf(8)","Fayxe(66)","Slfwyo(48)","Xbesji(70)","Pmbz(22)","Oip(2)","Fzoe(63)","Qync(79)","Utc(11)","Sqwejn(19)","Ngi(8)","Gsiiyo(60)","Bcs(73)","Icsvku(1)","Yzwm(92)","Vaakt(21)","Uvt(70)","Axaqkm(100)","Gyhh(84)","Gaoo(98)","Ghlj(35)","Umt(13)","Nfimij(52)","Zmeop(77)","Vje(29)","Rqa(47)","Upn(89)","Zhc(44)","Slh(66)","Orpqim(69)","Vxs(85)","Gql(19)","Sfjdjc(62)","Ccqunq(93)","Oyo(32)","Bvnkk(52)","Pxzfjg(45)","Kaaht(28)","Arrugl(57)","Vqnjg(50)","Dbufek(63)","Fshi(62)","Lvaaz(63)","Phlto(41)","Lnow(70)","Mqgga(31)","Adlue(82)","Zqiqe(27)","Mgs(46)","Zboes(56)","Dma(70)","Jnij(57)","Ghk(14)","Mrqlne(39)","Ljkzhs(35)","Rmlbnj(42)","Qszsny(93)","Aasipa(26)","Wzt(41)","Xuzubb(90)","Maeb(56)","Mlo(18)","Rttg(4)","Kmrev(31)","Kqjl(39)","Iggrg(47)","Mork(88)","Lwyfn(50)","Lcp(42)","Zpm(5)","Qlvglt(36)","Liyd(48)","Jxv(67)","Xaq(70)","Tkbn(81)","Rgd(85)","Ttj(28)","Ndc(62)","Bjfkzo(54)","Lqrmqh(50)","Vhdmab(41)"};
    vector<string> synonyms = {"(Uvt,Rqa)","(Qync,Kqjl)","(Fayxe,Upn)","(Maeb,Xaq)","(Pmbz,Vje)","(Hnc,Dma)","(Pwsuo,Gyhh)","(Gyhh,Aasipa)","(Fzoe,Lcp)","(Mgs,Vhdmab)","(Qync,Rgd)","(Gql,Liyd)","(Gyhh,Tkbn)","(Arrugl,Adlue)","(Wbcxi,Slfwyo)","(Yzwm,Vqnjg)","(Lnow,Vhdmab)","(Lvaaz,Rttg)","(Nfimij,Iggrg)","(Vje,Lqrmqh)","(Jylbla,Ljkzhs)","(Jnij,Mlo)","(Adlue,Zqiqe)","(Qync,Rttg)","(Gsiiyo,Vxs)","(Xxcl,Fzoe)","(Dbufek,Xaq)","(Ccqunq,Qszsny)","(Zmeop,Mork)","(Qync,Ngi)","(Zboes,Rmlbnj)","(Yldu,Jxv)","(Padz,Gsiiyo)","(Oip,Utc)","(Tal,Pxzfjg)","(Adlue,Zpm)","(Bbcpth,Mork)","(Qync,Lvaaz)","(Pmbz,Qync)","(Alqw,Ngi)","(Bcs,Maeb)","(Rgbu,Zmeop)"};
    Solution s;
    auto data = s.trulyMostPopular(names, synonyms);
    for (int loop_i = 0; loop_i < data.size(); ++loop_i) {
        std::cout << data[loop_i] << std::endl;
    }
}