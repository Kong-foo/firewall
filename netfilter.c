#include <stdio.h>

#include <linux/version.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/tcp.h>

#include <net/netlink.h>
#include <net/net_namespace.h>
#include <net/netns/generic.h>

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,16)
#include <linux/in.h>
#include <linux/ip.h>
#endif


unsigned int hookfunc(unsigned int hooknum, 
struct sk_buff **skb, const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff*)) {


}

int main(int argc, char **argv) {
struct list_head list;
struct nf_hook_ops nho;
//nho.list
nho.hook = hookfunc;
nho.owner = THIS_MODULE;
nho.pf = PF_INET;
nho.hooknum = NF_IP_LOCAL_OUT;
nho.priority = NF_IP_PRI_FIRST; //NF_IP_PRI_LAST

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,13,0)
    nf_register_net_hook(&init_net, reg)
#else
    nf_register_hook(reg)
#endif

nf_unregister_hook();

}
