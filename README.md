# MAVSec: Securing the MAVLink Protocol for Ardupilot/PX4 Unmanned Aerial Systems
Welcome to the repository for the research paper MAVSec: Securing the MAVLink Protocol for Ardupilot/PX4 Unmanned Aerial Systems.
This repository contains security extensions to MAVLink 2.0. 
MAVLink v2.0 has been changed to support different encryption scheme. This version has 4  implementations: RC4, AES-CBC, AES-CTR and ChaCha20. 
## Encryption algorithms:
### The Counter mode (CTR):
is a mode that turns a block cipher into a stream cipher and therefore used for achieving confidentiality. First, a stream of input blocks is generated, called counters. The counters are obtained from an initial counter *IV* , which is incremented and used to encrypt each block in turn. Then a forward cipher function is applied to these counters to produce a sequence of output blocks *r_{i}* that are exclusive-ORed with the plaintext *m_{i}* to produce the ciphertext *c_{i}*.
### The CBC mode:
CBC mode chains the previous ciphertext block with the current message block before the cipher function. The CBC mode takes a secret key $k$ as input, an Initialization Vector *IV*, which is randomly chosen with a length equal to the block length *N*, and the plaintext message. The plaintext is divided into several blocks *P_{1} \ldots P_{N}*, and each block is *XOR-ed* with the cipher data of the previous block before it is encrypted. The result of the $XOR$ operation is encrypted with the key *K* to produce ciphertext *C_{1} \ldots C_{N}*.
### RC4 :
The encryption of a message in RC4 is achieved by generating a keystream to be * XOR�ed*  with a stream of plaintext to produce a stream of ciphertext.
### ChaCha20:
ChaCha20 generates a keystream by applying the ChaCha20 block function to the *key*, *nonce*, and a *block counter*. Plaintext is then encrypted using this keystream, with block $i$ of the plaintext * XOR�ed* with the output of the ChaCha20 block function, evaluated using the block counter *i*.

The implementation involves the integration of the encryption algorithms AES-CTR, AES-CBC, ChaCha20 and RC4 both on the UAV autopilot side and GCS side integrated with the MAVLink protocol.
The MAVLink source code is modified to include cryptographic functions resulting in a successful encryption and decryption. The payload is fed to the encryption algorithm as an input to obtain encrypted data and then the checksum is computed. At the receiver's side, the checksum is checked and then the received encrypted data is decrypted.
## Completed tasks:
1.	Adding encryption scheme to MAVLink v2.0
2.	Added CTR mode in v2 with no padding 
3.	Added CBC mode in v2 
4.	Added RC4 mode in v2 with no padding 
5.	Added ChaCha20 mode in v2 with no padding 
6.	Added working v2.0 header files to the generator
## Execution:
1. To run Ardupilot, use the command ```sim_vehicle.py -j4 --console``` 
2. To run the udpserver.c, use the command  ```gcc -o UDPServ udpserver.c``` and ``` ./UDPServ 14550  ```




