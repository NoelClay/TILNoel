using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    public Rigidbody playerRigidbody;
    float speed = 8f;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //if (Input.GetKey(KeyCode.UpArrow) == true) playerRigidbody.AddForce(0f, 0f, speed);
        //if (Input.GetKey(KeyCode.DownArrow) == true) playerRigidbody.AddForce(0f, 0f, -speed);
        //if (Input.GetKey(KeyCode.RightArrow) == true) playerRigidbody.AddForce(speed, 0f, 0f);
        //if (Input.GetKey(KeyCode.LeftArrow) == true) playerRigidbody.AddForce(-speed, 0f, 0f);

        float xInput = Input.GetAxis("Horizontal");
        float zInput = Input.GetAxis("Vertical");

        float xSpeed = xInput * speed;
        float zSpeed = zInput * speed;

        Vector3 newVelocity = new Vector3(xSpeed, 0f, zSpeed);
        playerRigidbody.velocity = newVelocity;

    }
    public void Die()
    {
        gameObject.SetActive(false);
    }
}
