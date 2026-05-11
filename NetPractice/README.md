_This project has been created as part of the 42 curriculum by shashemi._

# NetPractice

### Description

NetPractice is a 42 project designed to introduce the fundamentals of computer networking. The goal is to configure small-scale networks by solving 10 levels involving IP addressing, subnetting, and routing. By completing it, you learn how devices communicate within a LAN and how they reach external networks through gateways and routing tables.

---

### Instructions

#### How to Run
1. Extract the project files into a folder of your choice.
2. Open a terminal in the project root.
3. Run the training script:
   ```bash
   ./run.sh
   ```
4. A web interface will open in your browser. Enter your 42 login to begin.

> If `run.sh` doesn't work, run manually:
> ```bash
> python3 -m http.server 49242
> ```
> Then go to `http://localhost:49242` in your browser.

#### How to Export and Submit
1. Solve a level.
2. Click **"Get my config"** to download the `.json` configuration file.
3. Repeat for all 10 levels.
4. Place the 10 files (`level1.json` to `level10.json`) at the **root** of your git repository.
5. Push the repository for evaluation.

#### During Evaluation
- The evaluator will use the **"evaluation"** tab to generate 3 random levels.
- You must solve them within a limited time.
- No external tools allowed (only a simple calculator like `bc` is tolerated).

#### Submission Structure
```text
level1.json
level2.json
level3.json
level4.json
level5.json
level6.json
level7.json
level8.json
level9.json
level10.json
README.md
```

---

### Resources

#### OSI Model (7 Layers)

| Layer | Name         | Role                          | Example          |
|-------|-------------|-------------------------------|------------------|
| 1     | Physical    | Transmits raw bits over cable | Ethernet cable   |
| 2     | Data Link   | Frames + MAC addressing       | Switch           |
| 3     | Network     | IP addressing + routing       | Router, IP       |
| 4     | Transport   | Reliable delivery (TCP/UDP)   | TCP, UDP ports   |
| 5     | Session     | Manages connections           | NetBIOS          |
| 6     | Presentation| Data format/encryption        | SSL, JPEG        |
| 7     | Application | User-facing protocols         | HTTP, DNS, FTP   |

In NetPractice we mainly work at **Layer 3 (Network)**: IP addresses, subnet masks, routing tables.

---

#### TCP/IP Addressing

- An **IPv4 address** is a 32-bit number written as 4 octets: `A.B.C.D` (e.g. `192.168.1.1`).
- Each octet ranges from `0` to `255`.
- An IP has two parts: **network portion** (identifies the network) and **host portion** (identifies the device).

**Private IP ranges** (not routable on the Internet):

| Class | Range                         | Default Mask      |
|-------|-------------------------------|-------------------|
| A     | `10.0.0.0` – `10.255.255.255`       | `255.0.0.0` /8   |
| B     | `172.16.0.0` – `172.31.255.255`     | `255.255.0.0` /16 |
| C     | `192.168.0.0` – `192.168.255.255`   | `255.255.255.0` /24 |

**Reserved addresses** (cannot be assigned to hosts):
- **Network address**: all host bits = 0 (e.g. `192.168.1.0/24`).
- **Broadcast address**: all host bits = 1 (e.g. `192.168.1.255/24`).
- `127.x.x.x`: loopback (localhost).
- `0.0.0.0`: default route / unspecified.

---

#### Subnet Masks

A subnet mask separates the **network** part from the **host** part of an IP.

**Quick CIDR cheat sheet:**

| CIDR | Subnet Mask       | Usable Hosts | Block Size |
|------|-------------------|-------------|------------|
| /30  | 255.255.255.252   | 2           | 4          |
| /28  | 255.255.255.240   | 14          | 16         |
| /27  | 255.255.255.224   | 30          | 32         |
| /26  | 255.255.255.192   | 62          | 64         |
| /25  | 255.255.255.128   | 126         | 128        |
| /24  | 255.255.255.0     | 254         | 256        |
| /16  | 255.255.0.0       | 65534       | 65536      |
| /8   | 255.0.0.0         | 16777214    | 16777216   |

**Formula:** Usable hosts = 2^(32 - CIDR) - 2

**How to find the network range:**
1. Convert mask to binary.
2. AND the IP with the mask → **network address**.
3. Invert the mask and OR with network → **broadcast address**.
4. Valid hosts: from network + 1 to broadcast - 1.

**Example:** `192.168.1.130/26`
- Mask: `255.255.255.192` → block size = 64
- Networks: `.0`, `.64`, `.128`, `.192`
- `130` falls in the `.128` block → network = `192.168.1.128`, broadcast = `192.168.1.191`
- Valid hosts: `192.168.1.129` – `192.168.1.190`

---

#### Default Gateway

- The gateway is the **IP of the router interface** on your local network.
- It's the "exit door" for packets going outside the subnet.
- A device **without a gateway** can only talk to devices on the same subnet.
- The gateway IP must be **within the same subnet** as the device.

---

#### Routers vs Switches

| Feature       | Switch (Layer 2)          | Router (Layer 3)               |
|---------------|---------------------------|-------------------------------|
| Operates on   | MAC addresses             | IP addresses                  |
| Connects      | Devices in the same LAN   | Different networks together   |
| Forwards      | Frames within a subnet    | Packets between subnets       |
| Needs IP?     | No                        | Yes (one per interface)       |

- A **switch** just forwards traffic inside the same network — no configuration needed in NetPractice.
- A **router** has multiple interfaces, each on a different subnet, and uses a **routing table** to forward packets.

---

#### Routing Tables

A routing table tells a router **where to send packets** based on their destination IP.

Each entry has:
- **Destination**: network address (or `0.0.0.0/0` for the default route = "everything else").
- **Next hop**: IP of the next router to forward the packet to.

**Key rules for NetPractice:**
1. Two devices on the **same subnet** communicate directly (no route needed, only matching IPs + masks).
2. For different subnets, each device needs a **gateway** pointing to the router.
3. The router needs a **route entry** for each destination network, or a **default route** (`0.0.0.0/0`) as a catch-all.
4. The `next hop` must be a **directly connected** router interface IP.

---

#### Common Mistakes in NetPractice
- Using the **network address** or **broadcast address** as a host IP.
- Gateway IP not in the **same subnet** as the host.
- Forgetting to add a **return route** (traffic must be able to go back).
- Overlapping subnets between different interfaces of a router.
- Using `127.x.x.x` as a regular IP (it's reserved for loopback).

---

### AI Usage

AI (GitHub Copilot) was used during this project for:
- **Conceptual clarification**: understanding networking concepts such as OSI model, subnetting, and routing tables.
- **README creation**: structuring and formatting this documentation.

All solutions to the 10 levels were worked through manually. No AI tool was used to solve the network configurations themselves.

---

### References

- [Subnet Cheat Sheet](https://www.aelius.com/njh/subnet_sheet.html) — quick CIDR ↔ mask conversions.
- [Networking Fundamentals (YouTube)](https://www.youtube.com/playlist?list=PLIFyRwBY_4bRLmKfP1KnZA6rZbRHtxmXi) — videos on devices, OSI, protocols.
- [NetPractice Guide by Sheldon Chong](https://github.com/Sheldon-Chong/netpractice) — walkthrough of this 42 project.
- [OSI Model Explained](https://datageneral.co/osi-model/) — detailed layer breakdown.
- [Subnetting 101](https://infosecwriteups.com/subnetting-101-simple-guide-to-ip-addressing-0a1ecac6a0ef) — simple guide to IP addressing.
