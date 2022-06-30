using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletControl : MonoBehaviour
{
    public float speed = 8f;
    public Rigidbody bulletRigidbody;

    // Start is called before the first frame update
    void Start()
    {
        bulletRigidbody = GetComponent<Rigidbody>();
        //앞쪽으로 스피드 곱한 값을 속도로 초기화
        bulletRigidbody.velocity = transform.forward * speed;
        Destroy(gameObject, 3f);//게임오브젝트 컴포넌트에 포함된 기능
    }
    private void OnTriggerEnter(Collider other)
    {
        if(other.tag == "Player")
        {
            PlayerController player = other.GetComponent<PlayerController>();

            if(player != null)
            {
                player.Die();
            }
        }
    }

}
