using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public GameObject gameoverTxt;
    public Text timeTxt;
    public Text recordTxt;

    float surviveTime;
    bool isGameover;

    // Start is called before the first frame update
    void Start()
    {
        surviveTime = 0f;
        isGameover = false;
    }

    // Update is called once per frame
    void Update()
    {
        if (!isGameover)
        {
            surviveTime += Time.deltaTime;
            timeTxt.text = "Time : " + (int)surviveTime;
        }
        else
        {
            if (Input.GetKeyDown(KeyCode.R))
            {
                SceneManager.LoadScene("SampleScene");
            }
        }
    }
    public void EndGame()
    {
        isGameover = true;
        gameoverTxt.SetActive(true);

        float bestTime = PlayerPrefs.GetFloat("BestTime");
        if(surviveTime > bestTime)
        {   //만약 겟플롯이 처음 실행된거면 0이기 때문에 무조건 set플롯됨
            bestTime = surviveTime;
            PlayerPrefs.SetFloat("BestTime", bestTime);
        }
        recordTxt.text = "Best Time : " + (int)bestTime;
    }

}
